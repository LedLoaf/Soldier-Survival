#ifndef ENEMY_MOVEMENT_AI_HPP_
#define ENEMY_MOVEMENT_AI_HPP_

#include <game/logic/MovementAI.hpp>

namespace game {

class Player;
class Enemy;
class FollowMovementAI;
class FreeMovementAI;

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

