#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <game/object/Character.hpp>
#include <weapon/Weapon.hpp>


namespace game {
    
class Enemy : public Character {
public:

    void setWeapon(Weapon* weapon);
    Weapon* gettWeapon();
    
private:
    Weapon* weapon;
    
};
    
}

#endif