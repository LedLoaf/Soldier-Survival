#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>

#include <game/object/Character.hpp>

#include "Equipment.hpp"

namespace view {
class MapViewModel;    
}

namespace game {

class Equipment;
class Weapon;    
class Bomb;
    
class Player : public Character {
public:
    Player(Equipment* equipment, view::MapViewModel* mapViewModel);
    
    Equipment* getEquipment();
    std::vector<game::Weapon*>* getWeapons();
    
    bool hasAnyWeapons();
    void setCurrentWeapon(Weapon* weapon);
    Weapon* getCurrentWeapon();
    
    Bomb* getBomb();
    int hasBomb();
    
    void injureUsing(Weapon* weapon);
 
    int getExperiencePoints();
    void addExperiencePoints(int points);
private:
    Weapon* currentWeapon;
    Equipment* equipment;
    int experience;
    
};
    
}

#endif