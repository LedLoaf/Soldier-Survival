#include <vector>
#include <algorithm>

#include <SFML/System/Mutex.hpp>
#include <SFML/System/Sleep.hpp>

#include <view/MapView.hpp>
#include <view/WarView.hpp>

#include "game/WarManager.hpp"
#include "game/BombManager.hpp"
#include <game/War.hpp>

namespace game {

BombManager::BombManager(view::MapView* mapView) {
    this->mapView = mapView;
    plantedBomb = NULL;
}

void BombManager::plantBomb(util::Location::Position* position, game::Bomb* bomb) {
    plantedBomb = bomb;
    bombPosition = position;
    
    mapView->putBomb(*bombPosition, plantedBomb);
    plantedBomb->setBombManager(this);
    plantedBomb->startTicking();
}


bool BombManager::checkIfBombHasBeenPlanted() {
    if (plantedBomb == NULL)
        return false;
    return true;
}


void BombManager::explodeBomb() {
    int bombLeftRangeOfDescruction = bombPosition->getX() - plantedBomb->getScope();
    
    if (bombLeftRangeOfDescruction < 0)
        bombLeftRangeOfDescruction = 0;
    
    int bombRightRangeOfDescruction = bombPosition->getX() + plantedBomb->getScope();
    
    if (bombRightRangeOfDescruction > mapView->getModel()->getMapWidth())
        bombRightRangeOfDescruction = mapView->getModel()->getMapWidth();
    
    int bombTopRangeOfDescruction = bombPosition->getY() - plantedBomb->getScope();
    
    if (bombTopRangeOfDescruction < 0)
        bombTopRangeOfDescruction = 0;
    
    int bombBottomRangeOfDescruction = bombPosition->getY() + plantedBomb->getScope();
    
    if (bombBottomRangeOfDescruction > mapView->getModel()->getMapHeight())
        bombBottomRangeOfDescruction = mapView->getModel()->getMapHeight();    
    
    
    for (int i = bombLeftRangeOfDescruction; i < bombRightRangeOfDescruction; i++)
        for (int j = bombTopRangeOfDescruction; j < bombBottomRangeOfDescruction; j++)
            if (mapView->getModel()->getCharacter(i, j) != NULL)
                mapView->getModel()->getCharacter(i, j)->injureUsing(plantedBomb);
    
        
    mapView->removeBomb(*bombPosition);
    delete plantedBomb;
    plantedBomb = NULL;
}

}
