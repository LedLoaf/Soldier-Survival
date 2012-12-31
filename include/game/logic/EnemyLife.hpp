#ifndef ENEMY_LIFE_HPP_
#define ENEMY_LIFE_HPP_

#include <game/logic/CharacterLife.hpp>

#include "MovementAI.hpp"

namespace game {
    
class MovementAI;    
    
class EnemyLife : public CharacterLife {
public:
    EnemyLife(int timeOfBirth, int lifetime);

    virtual void Run();

protected:
    bool isTimeToMove();

    MovementAI* movementAI;
    int lifetime; // -1 oznacza, ze zyje dopuki nie zostanie zabity
    int timeOfBirth;

};

}

#endif

