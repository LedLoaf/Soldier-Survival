#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <game/object/Character.hpp>



namespace game {

class Weapon;


class Enemy : public Character {
public:
    Enemy(MapObject::Type type);

    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    
    virtual void injureUsing(Weapon* weapon);
    
    bool canSeePlayer();    

    

private:
    Weapon* weapon;
    
};
    
}

#endif