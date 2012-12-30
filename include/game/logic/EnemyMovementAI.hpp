#ifndef ENEMY_MOVEMENTAI_HPP_
#define ENEMY_MOVEMENTAI_HPP_

#include <game/logic/MovementAI.hpp>
#include <game/logic/FollowMovementAI.hpp>
#include <game/logic/FreeMovementAI.hpp>

#include "object/Character.hpp"
#include <util/Location.hpp>


namespace game {

class EnemyMovementAI : public MovementAI {
public:
    EnemyMovementAI(Enemy* enemy, int movingTimeInterval);

    virtual void tryToDoNextMove();
    virtual void doNextMove();    

protected:
    Enemy* enemy;
    FollowMovementAI* followAI;
    FreeMovementAI* freeMovementAI;
    
};    

}

#endif

