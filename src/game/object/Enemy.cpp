#include <game/object/Enemy.hpp>


namespace game {

void Enemy::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}    

void Enemy::startMoving() {
    // MovementAI
    movementAI.moveToNextPosition();
            
}
    
}