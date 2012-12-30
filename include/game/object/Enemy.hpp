#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <game/object/Character.hpp>
#include <game/object/weapon/Weapon.hpp>


namespace game {
    
class Enemy : public Character {
public:
    Enemy();

    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    
    void injureUsing(Weapon* weapon);
    
    bool canSeePlayer();

private:
    Weapon* weapon;
    
};
    
}

#endif