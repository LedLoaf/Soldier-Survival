#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <game/object/Equipment.hpp>
#include <game/object/MapObject.hpp>

namespace game {
    
class Weapon : public Equipment::EquipmentItem {
public:
    
    Weapon(EquipmentItem::Type type);
    
    float getDamage();

    static bool isWeapon(Equipment::EquipmentItem* equipmentItem);
    static float getDamageFor(Equipment::EquipmentItem::Type weaponType);
    static Weapon* getWeaponFor(MapObject::Type characterType);
    
protected:
    float damage;
};
    
}

#endif