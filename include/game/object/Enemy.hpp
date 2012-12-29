#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <game/object/Character.hpp>
#include <game/object/weapon/Weapon.hpp>


namespace game {
    
class Enemy : public Character {
public:

    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    
    virtual void startMoving();
    
    void injureUsing(Weapon* weapon);
    


private:
    Weapon* weapon;
    
};
    
}

#endif