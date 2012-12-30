#include <game/object/Character.hpp>


namespace game {
    
void Character::startLife() {
    life->Launch();
}   

void Character::Life::Run() {
    if (isTimeToMove()) {
        movementAI->tryToDoNextMove();

    }

    if (isTimeToDie()) {

    }
}

bool Character::Life::isTimeToMove() {
    if (util::Util::getCurrentTime() - movementAI->getTimeOfLastMove() > movementAI->getMovingTimeInterval)
        return true;
    else
        return false;
}

bool Character::Life::isTimeToDie() {
    if (lifetime > -1) {
        if (util::Util::getCurrentTime() - timeOfBirth > lifetime)
            return true;
    } else 
        return false;
}

}