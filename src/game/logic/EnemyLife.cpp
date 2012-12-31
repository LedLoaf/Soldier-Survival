#include <math.h>
#include <time.h>
#include <cstdlib>
#include "game/logic/EnemyLife.hpp"
#include <game/logic/CharacterLife.hpp>
#include <game/logic/MovementAI.hpp>

#include <util/Util.hpp>

namespace game {

EnemyLife::EnemyLife(int timeOfBirth, int lifetime) : CharacterLife(timeOfBirth, lifetime) {
}

void EnemyLife::Run() {
    if (isTimeToMove()) {
        movementAI->tryToDoNextMove();

    }

    if (isTimeToDie()) {

    }
}

bool EnemyLife::isTimeToMove() {
    if ((util::Util::getCurrentTime() - movementAI->getTimeOfLastMove()) > movementAI->getMovingTimeInterval())
        return true;
    else
        return false;
}


}