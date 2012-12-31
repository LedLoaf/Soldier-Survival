#include <math.h>
#include <time.h>
#include <cstdlib>

#include <game/logic/MovementAI.hpp>

#include "game/logic/FreeMovementAI.hpp"

namespace game {

util::Location::Vector FreeMovementAI::getRandomDirection() {
    srand(time(NULL));

    util::Location::Vector directions[8] =  {util::Location::DOWN, util::Location::UP, util::Location::LEFT, util::Location::DOWN_LEFT,
                    util::Location::DOWN, util::Location::UP, util::Location::LEFT, util::Location::DOWN_LEFT};

    return directions[rand() % 8];
}    

}