#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <game/object/Equipment.hpp>

namespace game {
    
class Weapon : public Equipment::EquipmentItem {
public:
    
    Weapon(EquipmentItem::Type type);
    
    int getDamage();

    static bool isWeapon(Equipment::EquipmentItem* equipmentItem);
    
private:
    int damage;
};
    
}

#endif