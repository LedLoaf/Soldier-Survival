#include <cmath>

#include <SFML/System/Thread.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Mutex.hpp>

#include <view/View.hpp>
#include <view/WarView.hpp>

#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>
#include <game/War.hpp>

#include <util/Location.hpp>

#include "game/object/MapObject.hpp"
#include "game/BombManager.hpp"

namespace view {

MapView::MapView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
    this->warManager = new game::WarManager(this);
    this->bombManager = new game::BombManager(this);

}

MapView::~MapView() {
	delete mapViewModel;
    delete warManager;
    delete bombManager;    
}

void MapView::setModel(MapViewModel* mapModel) {
    this->mapViewModel = mapModel;
    this->mapViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
}

MapViewModel* MapView::getModel() {
    return mapViewModel;
}

void MapView::beginCharactersLife() {
    CharactersAnimator* charactersAnimator = new CharactersAnimator(this);
    charactersAnimator->Launch();
    while (charactersAnimator->stillWorking())
        continue;
//    
//    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 1, 
//            mapViewModel->getPlayer()->getPosition().getY() + 1)->beginLife();
//    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 2, 
//            mapViewModel->getPlayer()->getPosition().getY() + 2)->beginLife();
//    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 3, 
//            mapViewModel->getPlayer()->getPosition().getY() + 3)->beginLife();
//    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 4, 
//            mapViewModel->getPlayer()->getPosition().getY() + 4)->beginLife();
//    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 5, 
//            mapViewModel->getPlayer()->getPosition().getY() + 5)->beginLife();     
}

void MapView::showDeathOf(game::Character* ch) {
    mapViewModel->remove(ch->getPosition().getX(), ch->getPosition().getY(), ch);
    mapViewModel->put(ch->getPosition().getX(), ch->getPosition().getY(), 
            new game::NotMovingMapObject(game::MapObject::getDyingMapObjectFor(ch->getType())));
}

void MapView::buryCharacter(game::Character * ch) {
    mapViewModel->put(ch->getPosition().getX(), ch->getPosition().getY(),  
            new game::NotMovingMapObject(game::MapObject::GRASS));    
}

void MapView::moveCharacter(game::Character* ch, util::Location::Vector vector) {
    mapViewModelMutex.Lock();
	util::Location::Position position = mapViewModel->getPositionOf(ch);
	mapViewModel->remove(position.getX(), position.getY(), ch);
    
    util::Location::Position newPosition = position + vector;
	mapViewModel->put(newPosition.getX(), newPosition.getY(), ch);   
    mapViewModelMutex.Unlock();
}


void MapView::moveCharacter(game::Player* player, util::Location::Vector vector) {
    mapViewModelMutex.Lock();
	mapViewModel->remove(player->getPosition().getX(), player->getPosition().getY(), player);
    
    util::Location::Position newPosition = player->getPosition() + vector;
	mapViewModel->put(newPosition.getX(), newPosition.getY(), player);    
    mapViewModelMutex.Unlock();
}


bool MapView::canMoveCharacter(game::Character* ch, util::Location::Vector vector) {
	// MapView gra role MapHandlera
	// sprawdzam w tablicy z mapa czy jest taka mozliwosc
    // czy nie wyjde poza mape
    // czy na miejscu nie ma przeszkody lub innego charactera
    
    util::Location::Position nextPosition = ch->getPosition() + vector;
    
    if (isPositionInMapArea(nextPosition)) {
        
        // Na miejscu gdzie chce sie poruszyc postac stoi juz jakas inna postac
        game::Character* collidingCharacter = mapViewModel->getCharacter(nextPosition);
        if (collidingCharacter != NULL) {
            
            // kto sie zderza
            switch (ch->getType()) {
                
                case game::MapObject::PLAYER : {
            
                    // z kim sie zderza
                    switch (collidingCharacter->getType()) { 
                        case game::MapObject::ENEMY_A : {
                            if (!warManager->isWarAlreadyStartedBetween(
                                    dynamic_cast<game::Player*>(ch), dynamic_cast<game::Enemy*>(collidingCharacter)))
                                startWar(new game::War(dynamic_cast<game::Player*>(ch), dynamic_cast<game::Enemy*>(collidingCharacter)));
                            break;
                        }
                    }
                }
                
                case game::MapObject::ENEMY_A : 
                case game::MapObject::ENEMY_B :
                case game::MapObject::ENEMY_C : 
                case game::MapObject::ENEMY_D :
                case game::MapObject::ENEMY_E : {
            
                    // z kim sie zderza
                    switch (collidingCharacter->getType()) { 
                        case game::MapObject::PLAYER : {
                            
                            if (!warManager->isWarAlreadyStartedBetween(
                                    dynamic_cast<game::Player*>(collidingCharacter), dynamic_cast<game::Enemy*>(ch)))
                                startWar(new game::War(dynamic_cast<game::Player*>(collidingCharacter), dynamic_cast<game::Enemy*>(ch)));
                                
                        }

                    }
                }                
                
            }
            
            return false;
        } else {
            if (mapViewModel->hasNotMovingObjectAt(nextPosition.getX(), nextPosition.getY()) && 
                    (mapViewModel->getNotMovingObject(nextPosition)->getType() == game::MapObject::HEALTH_PACK ||
                     mapViewModel->getNotMovingObject(nextPosition)->getType() == game::MapObject::FOOD)) {
                getPlayer()->addHealth(35);
                mapViewModel->remove(nextPosition.getX(), nextPosition.getY(), 
                        dynamic_cast<game::NotMovingMapObject*>(mapViewModel->getNotMovingObject(nextPosition.getX(), nextPosition.getY())));
            }
                
            
            // canCharacterStayOnNMO(..) mowi nam, czy postac moze stanac na danym kafelku gdzie 
            // znajduje sie jakis obiekt nie poruszajacy sie - trawa, rzeka, skala, droga itd
            if (mapViewModel->hasNotMovingObjectAt(nextPosition.getX(), 
                    nextPosition.getY()) && !canCharacterStayOnNMMO(mapViewModel->getNotMovingObject(nextPosition)))
                return false;
            return true;
        }
        
    } else
        return false;
    
    
}

void MapView::startWar(game::War* war) {
    view::WarView* warView = new view::WarView(war->getWarModel());
    war->setWarView(warView);
    addView(warView);
    
    warManager->startWar(war);
}

void MapView::stopWar(game::War* war) {
    removeView(war->getWarView());
    warManager->stopWar(war);
}

util::Location::Position* MapView::getPlaceToPlantBomb() {
    util::Location::Position playerPosition = getPlayer()->getPosition();

    for (int x = playerPosition.getX() - 1; x < playerPosition.getX() + 1; x++)
        for (int y = playerPosition.getY() - 1; y < playerPosition.getY() + 1; y++)
            if (x > 0 && x < mapViewModel->getMapWidth() && y > 0 && y < mapViewModel->getMapHeight())
                if (game::MapObject::isTerrain(mapViewModel->getVisibleMapObject(x, y)))
                    return new util::Location::Position(x, y);

    return NULL;        
}

void MapView::tryToPlantBomb() {
    util::Location::Position* placeToPlantBomb = getPlaceToPlantBomb();
    
    if (getPlayer()->hasBomb() && placeToPlantBomb != NULL) {
        bombManager->plantBomb(getPlaceToPlantBomb(), getPlayer()->getBomb());
    }
}

void MapView::putBomb(util::Location::Position position, game::Bomb* bomb) {
    mapViewModelMutex.Lock();
    mapViewModel->put(position.getX(), position.getY(), 
            new game::NotMovingMapObject(game::MapObject::BOMB));    
    mapViewModelMutex.Unlock();
}

void MapView::removeBomb(util::Location::Position position) {
    mapViewModelMutex.Lock();
    mapViewModel->put(position.getX(), position.getY(), 
            new game::NotMovingMapObject(game::MapObject::GRASS));
    mapViewModelMutex.Unlock();  
}

bool MapView::checkIfBombHasBeenPlanted() {
    if (bombManager->checkIfBombHasBeenPlanted())
        return true;
    return false;
}

bool MapView::canCharacterStayOnNMMO(game::MapObject* notMovingMapObject) {
    if (game::MapObject::isTerrain(notMovingMapObject))
        return true;
    if (game::MapObject::isBridge(notMovingMapObject))
        return true;    
    if (game::MapObject::isRiver(notMovingMapObject))
        return false;
    if (game::MapObject::isWall(notMovingMapObject))
        return false;        
    if (notMovingMapObject->getType() == game::MapObject::TREE)
        return false;            
}

bool MapView::isPositionInMapArea(util::Location::Position position) {
    if (position.getX() > 0 && position.getX() < mapViewModel->getMapWidth() &&
            position.getY() > 0 && position.getY() < mapViewModel->getMapHeight())
        return true;
    else
        return false;
}

bool MapView::areColliding(game::Character* firstCharacter, game::Character* secondCharacter) {
//    std::cout << "MapView::getDistanceBetween(): " 
//            << MapView::getDistanceBetween(firstCharacter->getPosition(), secondCharacter->getPosition()) << std::endl;
    if (MapView::getDistanceBetween(firstCharacter->getPosition(), secondCharacter->getPosition()) == 1)
        return true;
    else
        return false;
}

int MapView::getDistanceBetween(util::Location::Position firstCharacterPosition, util::Location::Position secondCharacterPosition) {
    return pow( pow(firstCharacterPosition.getX() - secondCharacterPosition.getX(), 2) +
        pow(firstCharacterPosition.getY() - secondCharacterPosition.getY(), 2), 1.0/2 );
}

game::Player* MapView::getPlayer() {
    return mapViewModel->getPlayer();
}

void MapView::pause() {
    for (int i = 0; i < mapViewModel->getMapWidth(); i++) 
        for (int j = 0; j < mapViewModel->getMapHeight(); j++) {
            game::Character* ch = mapViewModel->getCharacter(i, j);
            if (ch != NULL)
                ch->pauseLife();
        }
}

void MapView::resume() {
    for (int i = 0; i < mapViewModel->getMapWidth(); i++) 
        for (int j = 0; j < mapViewModel->getMapHeight(); j++) {
            game::Character* ch = mapViewModel->getCharacter(i, j);
            if (ch != NULL)
                ch->resumeLife();
        }
}

View::Type MapView::getType() {
    return View::MAP_VIEW;
}

MapView::CharactersAnimator::CharactersAnimator(MapView* mapView) {
    this->mapView = mapView;
    this->mapViewModel = mapView->getModel();
    this->isWorking = true;
}

void MapView::CharactersAnimator::Run() {
    for (int i = 0; i < mapViewModel->getMapWidth(); i++) {
        for (int j = 0; j < mapViewModel->getMapHeight(); j++) {
            mapView->mapViewModelMutex.Lock();

            if (mapViewModel->getCharacter(i, j) != NULL && game::MapObject::isEnemy(mapViewModel->getCharacter(i, j )))
                if (!mapViewModel->getCharacter(i, j)->isAlive()) {
                    mapViewModel->getCharacter(i, j)->beginLife();
                    std::cout << "MapView::CharactersAnimator::Run(): animating one more character" << std::endl;
                }
            mapView->mapViewModelMutex.Unlock();
            
            //sf::Sleep(0.000000001f);
        }        
    }    
    isWorking = false;
    std::cout << "MapView::CharactersAnimator::Run(): end" << std::endl;
    
}

bool MapView::CharactersAnimator::stillWorking() {
    return isWorking;
}

}
