#include <view/View.hpp>
#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>

#include <util/Location.hpp>

#include "game/object/MapObject.hpp"

namespace view {

MapView::MapView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
    warView = new WarView();

}


void MapView::moveCharacter(game::Character* ch, util::Location::Vector vector) {
	util::Location::Position position = mapViewModel->getPositionOf(ch);

	mapViewModel->remove(position.getX(), position.getY(), ch);
    
    util::Location::Position newPosition = position + vector;
	mapViewModel->put(newPosition.getX(), newPosition.getY(), ch);    
    ch->setPosition(position);
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
                            if (!warManager->isWarAlreadyStartedBetween(ch, collidingCharacter))
                                warManager->startWar(new game::War(ch, collidingCharacter));
                        }

                    }
                }
                
            }
            
            return false;
        } else {
            // canCharacterStayOnNMO(..) mowi nam, czy postac moze stanac na danym kafelku gdzie 
            // znajduje sie jakis obiekt nie poruszajacy sie - trawa, rzeka, skala, droga itd
            if (!canCharacterStayOnNMMO(mapViewModel->getNotMovingObject(chPosition + vector)))
                return false;
            return true;
        }
        
    } else
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


View::Type MapView::getType() {
    return View::MAP_VIEW;
}

}
