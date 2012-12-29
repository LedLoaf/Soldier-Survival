#ifndef ENEMY_MOVEMENTAI_HPP_
#define ENEMY_MOVEMENTAI_HPP_

#include <game/MovementAI.hpp>


namespace game {

class EnemyMovementAI : public MovementAI {
public:
    EnemyMovementAI(Enemy* enemy)  : MovementAI() {
        this->enemy = enemy;
    }

    virtual void move() {
        // na danej podstawie okresl kierunek - direction
        util::Location::Vector direction = util::Location::DOWN;
        if (mapView->canMoveCharacter(enemy, direction)) 
            mapView->moveCharacter(enemy, direction); 
        else {
            // okresl kierunek na nowo
        }

    }

protected:
    Enemy* enemy;
};    

}

#endif

