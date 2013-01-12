#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>

#include <game/object/Character.hpp>

#include "Equipment.hpp"


namespace game {

class Equipment;
class Weapon;    
    
class Player : public Character {
public:
    Player(Equipment* equipment);
    
    Equipment* getEquipment();
    std::vector<game::Weapon*>* getWeapons();
    
    bool hasAnyWeapons();
    void setCurrentWeapon(Weapon* weapon);
    Weapon* getCurrentWeapon();
    
    void injureUsing(Weapon* weapon);
    
private:
    Weapon* currentWeapon;
    Equipment* equipment;
    
};
    
}

#endif