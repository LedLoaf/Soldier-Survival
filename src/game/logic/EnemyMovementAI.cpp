#include <util/Location.hpp>

#include <game/logic/EnemyMovementAI.hpp>
#include <game/logic/FollowMovementAI.hpp>
#include <game/logic/FreeMovementAI.hpp>

#include <game/object/Enemy.hpp>
#include <game/object/Player.hpp>

#include <view/MapView.hpp>

#include "game/Application.hpp"
#include "view/window/GamePlayWindow.hpp"




namespace game {

EnemyMovementAI::EnemyMovementAI(Enemy* enemy, int movingTimeInterval)  : MovementAI(movingTimeInterval) {
    this->enemy = enemy;
}

void EnemyMovementAI::tryToDoNextMove() {
    mapView = dynamic_cast<view::GamePlayWindow*>(Application::getInstance().getContext()->getActiveWindow())->getMapView();
    
    if (enemy->canSeePlayer()) {
        // 8 elementowa tablica
        util::Location::Vector* directionsToPlayer = 
                followAI->getDirectionsToCharacter(mapView->getPlayer()->getPosition(), enemy->getPosition());

        bool moveWasMade = false;
        int i = 0;
        while (!moveWasMade && i < 8) {
            if (mapView->canMoveCharacter(enemy, directionsToPlayer[i])) {
                mapView->moveCharacter(enemy, directionsToPlayer[i]);
                moveWasMade = true;
            } else 
                i++;

        }
    } else {
        util::Location::Vector direction = freeMovementAI->getRandomDirection();

        if (mapView->canMoveCharacter(enemy, direction)) 
            mapView->moveCharacter(enemy, direction);        

    }

}

void EnemyMovementAI::doNextMove() {
}    
    

}