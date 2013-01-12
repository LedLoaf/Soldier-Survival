#include <math.h>
#include <time.h>
#include <cstdlib>

#include <game/logic/CharacterLife.hpp>
#include <util/Util.hpp>

namespace game {

CharacterLife::CharacterLife(int timeOfBirth, int lifetime) {
    this->timeOfBirth = timeOfBirth;
    this->lifetime = lifetime;
    this->stillAlive = true;
}


bool CharacterLife::isTimeToDie() {
    if (lifetime > -1) {
        if (util::Util::getCurrentTime() - timeOfBirth > lifetime)
            return true;
    } else 
        return false;
}

}