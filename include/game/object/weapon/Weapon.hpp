#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <game/object/Equipment.hpp>

namespace game {
    
class Weapon : public Equipment::EquipmentItem {
public:
    
    Weapon(Equipment::EquipmentItem::Type type);
    
    Equipment::EquipmentItem::Type getType();
    int getDamage();

    static bool isWeapon(Equipment::EquipmentItem* equipmentItem);
    
private:
    Equipment::EquipmentItem::Type type;
    int damage;
};
    
}

#endif