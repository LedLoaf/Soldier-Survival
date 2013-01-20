#include <iostream>

#include <util/Util.hpp>

#include <game/object/Character.hpp>
#include <game/object/Player.hpp>
#include <game/object/Enemy.hpp>
#include <game/logic/EnemyMovementAI.hpp>
#include <game/logic/EnemyLife.hpp>

#include <game/object/weapon/Weapon.hpp>

#include <view/window/GamePlayWindow.hpp>
#include "view/MapView.hpp"
#include "game/Application.hpp"
#include "view/window/GamePlayWindow.hpp"

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
            if (distance < 4)
                return true;
            break;
        case MapObject::ENEMY_B:
            if (distance < 2)
                return true;
            break;
        case MapObject::ENEMY_C:
            if (distance < 3)
                return true;  
            break;
        case MapObject::ENEMY_D:
            if (distance < 3)
                return true;
            break;
        case MapObject::ENEMY_E:
                return true; 
        default:
                return false;                
    }
    return false;
}

void Enemy::injureUsing(Weapon* weapon) {
//    std::cout << "Enemy::injureUsing(), getDamage(): " << weapon->getDamage() << std::endl;
    
    health -= weapon->getDamage();
    
    if (health <= 0)
        endLife();
    
    // TODO: jak bedzie czas, zamienic na wzorzec Subscriber - Publisher
    view::Window* activeWindow = Application::getInstance().getContext()->getActiveWindow();
    if (activeWindow->getType() == view::Window::GAME_PLAY_WINDOW) {
        Player* player = dynamic_cast<view::GamePlayWindow*>(activeWindow)->getMapView()->getPlayer();
    // TODO: jakos sensowniej przyznawac te punkty doswiadczenia ;). Moze od szybkosci zabicia, itp.
        player->addExperiencePoints(weapon->getDamage() * 10 * (util::Util::getCurrentTime() % 3)); 
    }
    
}

}