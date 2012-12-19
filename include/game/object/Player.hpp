#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <game/object/Character.hpp>

#include "weapon/Weapon.hpp"


namespace game {
    
class Player : public Character {
public:
    Player(Equipment* equipment);
    
    Equipment* getEquipment();
    std::vector<game::Weapon*>* getWeapons();
    
    void setCurrentWeapon(Weapon* weapon) {
        currentWeapon = weapon;
    }
    
    void setHealth(int health);
    int getHealth();
    
    Weapon* getCurrentWeapon();
    
private:
    Weapon* currentWeapon;
    
};
    
}

#endif