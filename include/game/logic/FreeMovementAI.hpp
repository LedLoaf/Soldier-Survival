#ifndef FREE_MOVEMENT_AI_HPP_
#define FREE_MOVEMENT_AI_HPP_

#include <util/Location.hpp>

namespace game {
    
class FreeMovementAI {
public:
    util::Location::Vector getRandomDirection();
};

}

#endif

