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
    
    Weapon* getCurrentWeapon();
    
    void setHealth(int health);
    int getHealth();
    
    
    void injureUsing(Weapon* weapon);
    
private:
    Weapon* currentWeapon;
    
};
    
}

#endif