#include <game/object/weapon/Weapon.hpp>

#include "game/object/Equipment.hpp"

namespace game {
    
Weapon::Weapon(Weapon::Type type) {
    this->type = type;
    damage = 350;
}

Weapon::Type Weapon::getType() {
    return type;
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


}
