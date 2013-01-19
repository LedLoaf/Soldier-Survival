#include <cmath>

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

void MapView::setModel(MapViewModel* mapModel) {
    this->mapViewModel = mapModel;
    this->mapViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
}

MapViewModel* MapView::getModel() {
    return mapViewModel;
}

void MapView::beginCharactersLife() {
//    for (int i = 0; i < mapViewModel->getMapWidth(); i++) {
//        for (int j = 0; j < mapViewModel->getMapHeight(); j++) {
//            if (mapViewModel->getCharacter(i, j) != NULL && mapViewModel->getCharacter(i, j)->getType() == game::MapObject::ENEMY_A)
//                mapViewModel->getCharacter(i, j)->beginLife();
//        }        
//    }
    
    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 1, 
            mapViewModel->getPlayer()->getPosition().getY() + 1)->beginLife();
    mapViewModel->getCharacter(mapViewModel->getPlayer()->getPosition().getX() + 2, 
            mapViewModel->getPlayer()->getPosition().getY() + 2)->beginLife();    
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
	util::Location::Position position = mapViewModel->getPositionOf(ch);
	mapViewModel->remove(position.getX(), position.getY(), ch);
    
    util::Location::Position newPosition = position + vector;
	mapViewModel->put(newPosition.getX(), newPosition.getY(), ch);    
}


void MapView::moveCharacter(game::Player* player, util::Location::Vector vector) {
	mapViewModel->remove(player->getPosition().getX(), player->getPosition().getY(), player);
    
    util::Location::Position newPosition = player->getPosition() + vector;
	mapViewModel->put(newPosition.getX(), newPosition.getY(), player);    
}


bool MapView::canMoveCharacter(game::Character* ch, util::Location::Vector vector) {
	// MapView gra role MapHandlera
	// sprawdzam w tablicy z mapa czy jest taka mozliwosc
    // czy nie wyjde poza mape
    // czy na miejscu nie ma przeszkody lub innego charactera
    
    util::Location::Position chPosition = ch->getPosition();
    
    // sprawdzamy, czy nie chcemy sie poruszyc poza mape
    if (isPositionInMapArea(chPosition + vector)) {
        
        // Na miejscu gdzie chce sie poruszyc postac stoi juz jakas inna postac
        game::Character* collidingCharacter = mapViewModel->getCharacter(chPosition + vector);
        if (collidingCharacter != NULL) {
            // kolizja
            
            switch (ch->getType()) {
                
                // Gracz zderza sie z inna postacia
                case game::MapObject::PLAYER : {
            
                    switch (collidingCharacter->getType()) { 
                        case game::MapObject::ENEMY_A : {
                            
                            
                            if (!warManager->isWarAlreadyStartedBetween(
                                    dynamic_cast<game::Player*>(ch), dynamic_cast<game::Enemy*>(collidingCharacter)))
                                startWar(new game::War(dynamic_cast<game::Player*>(ch), dynamic_cast<game::Enemy*>(collidingCharacter)));
                                
                        }

                    }
                }
                
            }
            
            return false;
        } else {
            // canCharacterStayOnNMO(..) mowi nam, czy postac moze stanac na danym kafelku gdzie 
            // znajduje sie jakis obiekt nie poruszajacy sie - trawa, rzeka, skala, droga itd
            util::Location::Position nextPosition = chPosition + vector;
            if (mapViewModel->hasNotMovingObjectAt(nextPosition.getX(), nextPosition.getY()) && !canCharacterStayOnNMMO(mapViewModel->getNotMovingObject(chPosition + vector)))
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
    mapViewModel->put(position.getX(), position.getY(), 
            new game::NotMovingMapObject(game::MapObject::BOMB));    
}

void MapView::removeBomb(util::Location::Position position) {
    mapViewModel->put(position.getX(), position.getY(), 
            new game::NotMovingMapObject(game::MapObject::GRASS));    
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



}
