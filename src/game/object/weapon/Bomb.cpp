#include <SFML/System/Thread.hpp>
#include <SFML/System/Sleep.hpp>

#include <game/object/weapon/Weapon.hpp>

#include <game/object/MapObject.hpp>
#include <game/object/weapon/Weapon.hpp>
#include "game/object/Equipment.hpp"
#include "game/object/MapObject.hpp"
#include "game/object/weapon/Bomb.hpp"
#include "game/BombManager.hpp"

namespace game {
 
Bomb::Bomb(EquipmentItem::Type type, int explodeTime, int bombScope) : Weapon(type), MapObject(game::MapObject::BOMB) {
    this->explodeTime = explodeTime;
    this->bombScope = bombScope;    
    this->damage = 50;
}    
    
Bomb::Bomb(EquipmentItem::Type type, int explodeTime, int bombScope, BombManager* bombManager) : Weapon(type), MapObject(game::MapObject::BOMB) {
    this->explodeTime = explodeTime;
    this->bombScope = bombScope;
    this->bombManager = bombManager;
    this->damage = 50;
}    

void Bomb::setBombManager(BombManager* bombManager) {
    this->bombManager = bombManager;
}

void Bomb::startTicking() {
    Launch();
}

int Bomb::getScope() {
    return bombScope;
}

void Bomb::Run() {
    for (int i = 0; i < explodeTime; i++)           
        sf::Sleep(1);            
    
    
    bombManager->explodeBomb();
}


game::MapObject::Type Bomb::getType() {
    return game::MapObject::BOMB;
}

}
