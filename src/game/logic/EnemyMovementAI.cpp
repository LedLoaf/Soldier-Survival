
#include "game/logic/EnemyMovementAI.hpp"



namespace game {

EnemyMovementAI::EnemyMovementAI(Enemy* enemy, int movingTimeInterval)  : MovementAI(movingTimeInterval) {
    this->enemy = enemy;
}

void EnemyMovementAI::tryToDoNextMove() {
    if (enemy->canSeePlayer()) {
        util::Location::Vector directionsToPlayer[8] = 
                followAI->getDirectionsToPlayerFrom(enemy->getPosition());

        bool moveWasMade = false;
        int i = 0;
        while (!moveWasMade) {
            if (mapView->canMoveCharacter(enemy, directionsToPlayer[i])) {
                mapView->moveCharacter(enemy, directionsToPlayer[i])
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