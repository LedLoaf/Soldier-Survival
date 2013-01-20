#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <game/object/Character.hpp>

namespace view {
class MapViewModel;    
}

namespace game {

class Weapon;
class EnemyMovementAI;


class Enemy : public Character {
public:
    Enemy(MapObject::Type type, view::MapViewModel* mapViewModel);
    
    
    void setWeapon(Weapon* weapon);
    Weapon* getWeapon();
    
    virtual void injureUsing(Weapon* weapon);
    
    bool canSeePlayer();    

    

private:
    Weapon* weapon;
    EnemyMovementAI* movementAI;
    
};
    
}

#endif