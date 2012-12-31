#include <util/Util.hpp>

#include <game/object/Character.hpp>
#include <game/object/Enemy.hpp>
#include <game/logic/EnemyMovementAI.hpp>
#include <game/logic/EnemyLife.hpp>


namespace game {

Enemy::Enemy(MapObject::Type type) : Character(type) {
    life = new EnemyLife(util::Util::getCurrentTime(), -1);
    movementAI = new game::EnemyMovementAI(this, 100); // co 100ms bedzie sie poruszac
} 

void Enemy::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

Weapon* Enemy::getWeapon() {
    return weapon;
}    


bool Enemy::canSeePlayer() {
    return false;
}

void Enemy::injureUsing(Weapon* weapon) {
    
}

}