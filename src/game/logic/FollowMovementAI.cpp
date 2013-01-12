#include <math.h>
#include <time.h>
#include <cstdlib>

#include <util/Location.hpp>
#include "game/logic/FollowMovementAI.hpp"


namespace game {

util::Location::Vector* FollowMovementAI::getDirectionsToCharacter(util::Location::Position characterPosition, 
        util::Location::Position startPosition) {
    util::Location::Vector* directions =  new util::Location::Vector[8];
    
    util::Location::Vector verticalVector = util::Location::NOWHERE;
    util::Location::Vector horizontalVector = util::Location::NOWHERE;

    
    if (startPosition.getY() > characterPosition.getY())
        verticalVector = util::Location::UP;
    else if (startPosition.getY() < characterPosition.getY())
        verticalVector = util::Location::DOWN;
    
    if (startPosition.getX() > characterPosition.getX())
        horizontalVector = util::Location::LEFT;
    else if (startPosition.getX() < characterPosition.getX()) 
        horizontalVector = util::Location::RIGHT;
    
    
    
    directions[0] = util::Location::getVectorSum(verticalVector, horizontalVector);
    
    util::Location::Vector vectorSum = util::Location::getVectorSum(verticalVector, horizontalVector);
    
    // jest po przekatnej
    if (verticalVector != util::Location::NOWHERE && horizontalVector != util::Location::NOWHERE) {
        directions[1] = verticalVector;
        directions[2] = horizontalVector;
        directions[3] = util::Location::getVectorSum(verticalVector, util::Location::getOppositeVector(horizontalVector));
        directions[4] = util::Location::getVectorSum(util::Location::getOppositeVector(verticalVector), horizontalVector);
        directions[5] = util::Location::getOppositeVector(verticalVector);
        directions[6] = util::Location::getOppositeVector(horizontalVector);
        //..
    }
    //jest w pionie
    else if (verticalVector != util::Location::NOWHERE && horizontalVector == util::Location::NOWHERE) {
        directions[1] = util::Location::getVectorSum(verticalVector, util::Location::LEFT);
        directions[2] = util::Location::getVectorSum(verticalVector, util::Location::RIGHT);
        directions[3] = util::Location::LEFT;
        directions[4] = util::Location::RIGHT;
        directions[5] = util::Location::getVectorSum(util::Location::getOppositeVector(verticalVector), util::Location::LEFT);        
        directions[6] = util::Location::getVectorSum(util::Location::getOppositeVector(verticalVector), util::Location::RIGHT);
        directions[7] = util::Location::getOppositeVector(verticalVector);
    }
    //jest w poziomie
    else if (horizontalVector != util::Location::NOWHERE && verticalVector == util::Location::NOWHERE) {
        directions[1] = util::Location::getVectorSum(horizontalVector, util::Location::UP);
        directions[2] = util::Location::getVectorSum(horizontalVector, util::Location::DOWN);
        directions[3] = util::Location::UP;
        directions[4] = util::Location::DOWN;
        directions[5] = util::Location::getVectorSum(util::Location::getOppositeVector(horizontalVector), util::Location::UP);        
        directions[6] = util::Location::getVectorSum(util::Location::getOppositeVector(horizontalVector), util::Location::DOWN);
        directions[7] = util::Location::getOppositeVector(horizontalVector);
    }    
    
    
    
    return directions;
}

}