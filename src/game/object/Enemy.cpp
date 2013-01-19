#include <iostream>

#include <util/Util.hpp>

#include <game/object/Character.hpp>
#include <game/object/Player.hpp>
#include <game/object/Enemy.hpp>
#include <game/logic/EnemyMovementAI.hpp>
#include <game/logic/EnemyLife.hpp>

#include <game/object/weapon/Weapon.hpp>

#include "view/MapView.hpp"

namespace game {

Enemy::Enemy(MapObject::Type type, view::MapViewModel* mapViewModel) : Character(type, mapViewModel) {
    movementAI = new game::EnemyMovementAI(this, 100); // co 100ms bedzie sie poruszac    
    life = new EnemyLife(this, util::Util::getCurrentTime(), -1, movementAI);
    
    
    this->weapon = game::Weapon::getWeaponFor(type);
} 

void Enemy::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

Weapon* Enemy::getWeapon() {
    return weapon;
}    


bool Enemy::canSeePlayer() {
    int distance = mapView->getDistanceBetween(getPosition(), mapViewModel->getPlayer()->getPosition());
    
    switch (type) {
        case MapObject::ENEMY_A:
            if (distance < 6)
                return true;
        default:
                return false;                
    }
}

void Enemy::injureUsing(Weapon* weapon) {
//    std::cout << "Enemy::injureUsing(), getDamage(): " << weapon->getDamage() << std::endl;
    
    health -= weapon->getDamage();
    
    if (health <= 0)
        endLife();
}

}