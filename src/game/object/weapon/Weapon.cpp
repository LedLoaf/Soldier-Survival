#include <game/object/weapon/Weapon.hpp>

#include "game/object/Equipment.hpp"
#include "game/object/MapObject.hpp"

namespace game {
    
Weapon::Weapon(EquipmentItem::Type type) : EquipmentItem(type) {
    damage = 350;
}


int Weapon::getDamage() {
    return damage;
}

bool Weapon::isWeapon(Equipment::EquipmentItem* equipmentItem) {
    switch (equipmentItem->getType()) {
        case Equipment::EquipmentItem::GUN :
        return true;
        case Equipment::EquipmentItem::KNIFE :
        return true;
        case Equipment::EquipmentItem::RIFLE :
        return true;        
    }
}

Weapon* Weapon::getWeaponFor(MapObject::Type characterType) {
    return new Weapon(Equipment::EquipmentItem::GUN);
}


}
