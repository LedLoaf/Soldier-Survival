#include <game/object/weapon/Weapon.hpp>

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



}
