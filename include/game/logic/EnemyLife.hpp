#ifndef ENEMY_LIFE_HPP_
#define ENEMY_LIFE_HPP_

#include <game/logic/CharacterLife.hpp>

#include "MovementAI.hpp"

namespace game {
    
class EnemyMovementAI;    
    
class EnemyLife : public CharacterLife {
public:
    EnemyLife(Character* ch, int timeOfBirth, int lifetime, EnemyMovementAI* movementAI);
    ~EnemyLife();
    
    virtual void Run();

protected:
    bool isTimeToMove();

    EnemyMovementAI* movementAI;
    int lifetime; // -1 oznacza, ze zyje dopuki nie zostanie zabity
    int timeOfBirth;

};

}

#endif

