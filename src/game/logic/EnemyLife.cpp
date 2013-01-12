#include <math.h>
#include <time.h>
#include <cstdlib>

#include <SFML/System/Sleep.hpp>

#include "game/logic/EnemyLife.hpp"
#include <game/logic/CharacterLife.hpp>
#include <game/logic/MovementAI.hpp>
#include <game/logic/EnemyMovementAI.hpp>

#include <util/Util.hpp>

namespace game {

EnemyLife::EnemyLife(int timeOfBirth, int lifetime, EnemyMovementAI* movementAI) : CharacterLife(timeOfBirth, lifetime) {
    this->movementAI = movementAI;
}

void EnemyLife::Run() {
    while (stillAlive) {
//        if (isTimeToMove()) {
            movementAI->tryToDoNextMove();

//        }

        
        if (isTimeToDie()) {

        }
            
        sf::Sleep(0.8f);            
    }
}

bool EnemyLife::isTimeToMove() {
    if ((util::Util::getCurrentTime() - movementAI->getTimeOfLastMove()) > movementAI->getMovingTimeInterval())
        return true;
    else
        return false;
}


}