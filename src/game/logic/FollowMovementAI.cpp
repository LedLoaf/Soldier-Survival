#include <math.h>
#include <time.h>
#include <cstdlib>

#include <util/Location.hpp>
#include "game/logic/FollowMovementAI.hpp"


namespace game {

util::Location::Vector* FollowMovementAI::getDirectionsToPlayerFrom(util::Location::Position position) {
    util::Location::Vector directions[8] =  {util::Location::DOWN, util::Location::UP, util::Location::LEFT, util::Location::DOWN_LEFT,
                    util::Location::DOWN, util::Location::UP, util::Location::LEFT, util::Location::DOWN_LEFT};
    
    return directions;
}

}