#include <game/object/Enemy.hpp>


namespace game {

Enemy::Enemy() {
    life = new Character::Life(util::Util::getCurrentTime(), -1, );
    movementAI = new EnemyMovementAI(this, 100); // co 100ms bedzie sie poruszac
} 

void Enemy::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}    

    
}