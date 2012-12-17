#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <game/object/Character.hpp>

#include "weapon/Weapon.hpp"


namespace game {
    
class Player : public Character {
public:
    Player(Equipment* equipment);
    
    Equipment* getEquipment();
    
    void setCurrentWeapon(Weapon* weapon) {
        currentWeapon = weapon;
    }
    
    Weapon* getCurrentWeapon();
    
private:
    Weapon* currentWeapon;
    
};
    
}

#endif