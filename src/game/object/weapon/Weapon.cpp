#include <game/object/weapon/Weapon.hpp>

#include "game/object/Equipment.hpp"
#include "game/object/MapObject.hpp"

namespace game {
    
Weapon::Weapon(EquipmentItem::Type type) : EquipmentItem(type) {
    damage = Weapon::getDamageFor(type);
}

float Weapon::getDamage() {
    return damage;
}

bool Weapon::isWeapon(Equipment::EquipmentItem* equipmentItem) {
    switch (equipmentItem->getType()) {
        case Equipment::EquipmentItem::SWORD :
            return true;
        case Equipment::EquipmentItem::KNIFE :
            return true;
        case Equipment::EquipmentItem::AX :
            return true;        
    }
}

float Weapon::getDamageFor(Equipment::EquipmentItem::Type weaponType) {
    switch (weaponType) {
        case Equipment::EquipmentItem::SWORD :
            return 3;
        case Equipment::EquipmentItem::ENEMY_SWORD :
            return 0.3;            
        case Equipment::EquipmentItem::KNIFE :
            return 1;
        case Equipment::EquipmentItem::AX :
            return 4;  
        default:
            return 0;
    }    
}

Weapon* Weapon::getWeaponFor(MapObject::Type characterType) {
    return new Weapon(Equipment::EquipmentItem::ENEMY_SWORD);
}


}
