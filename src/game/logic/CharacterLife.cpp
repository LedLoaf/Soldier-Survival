#include <math.h>
#include <time.h>
#include <cstdlib>

#include <game/logic/CharacterLife.hpp>
#include <util/Util.hpp>

#include "game/object/Character.hpp"

namespace game {

CharacterLife::CharacterLife(Character* ch, int timeOfBirth, int lifetime) {
    this->character = ch;
    this->timeOfBirth = timeOfBirth;
    this->lifetime = lifetime;
    this->stillAlive = true;
    this->isPaused = false;
}

void CharacterLife::Run() {
}

void CharacterLife::pause() {
    isPaused = true;
}

void CharacterLife::resume() {
    isPaused = false;
}

bool CharacterLife::isTimeToDie() {
    if (lifetime > -1) {
        if (util::Util::getCurrentTime() - timeOfBirth > lifetime)
            return true;
    } else 
        return false;
}

void CharacterLife::die() {
    stillAlive = false;
}

}