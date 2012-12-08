#include <game/object/weapon/Weapon.hpp>

namespace game {
    
Weapon::Weapon(Weapon::Type type) {
    this->type = type;
}

Weapon::Type Weapon::getType() {
    return type;
}

}
