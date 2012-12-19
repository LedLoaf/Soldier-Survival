#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <game/object/Character.hpp>

#include "weapon/Weapon.hpp"


namespace game {
    
class Trader : public Character {
public:
    Trader(Equipment* equipment);
    
    Equipment* getEquipment();
    

    
private:
    
};
    
}

#endif