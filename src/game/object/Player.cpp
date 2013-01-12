#include <vector>

#include <game/object/Character.hpp>
#include "game/object/Player.hpp"
#include <game/object/Equipment.hpp>
#include "game/object/weapon/Weapon.hpp"
#include <view/model/MapViewModel.hpp>


namespace game {

Player::Player(Equipment* equipment, view::MapViewModel* mapViewModel) : Character(MapObject::PLAYER, mapViewModel) {
    this->equipment = equipment;
    
    if (hasAnyWeapons())
        this->currentWeapon = getWeapons()->at(0);        
    else
        this->currentWeapon = NULL;
}


bool Player::hasAnyWeapons() {
    if (getWeapons()->size() > 0) 
        return true;
    return false;
}

Equipment* Player::getEquipment() {
    return equipment;
}

std::vector<game::Weapon*>* Player::getWeapons() {
    std::vector<game::Weapon*>* weapons = new std::vector<game::Weapon*>();
    
    for(std::vector<Equipment::EquipmentItem*>::iterator it = equipment->getItems()->begin(); it != equipment->getItems()->end(); ++it) {
        switch ((*it)->getType()) {
            case Equipment::EquipmentItem::GUN || Equipment::EquipmentItem::KNIFE || Equipment::EquipmentItem::RIFLE:
                weapons->push_back((Weapon*)(*it));
        }        
    }

    return weapons;
}

void Player::setCurrentWeapon(Weapon* weapon) {
    currentWeapon = weapon;
}

Weapon* Player::getCurrentWeapon() {
    return currentWeapon;
}

void Player::injureUsing(Weapon* weapon) {
    
}
    
}