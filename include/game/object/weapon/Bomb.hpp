#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <SFML/System/Thread.hpp>


#include <game/object/MapObject.hpp>

#include <game/object/Equipment.hpp>
#include <game/object/MapObject.hpp>

#include "Weapon.hpp"

namespace game {
    
class BombManager;    
    
class Bomb : public Weapon, sf::Thread, MapObject {
public:
    Bomb(EquipmentItem::Type type, int explodeTime, int bombScope);
    Bomb(EquipmentItem::Type type, int explodeTime, int bombScope, BombManager* bombManager);
    
    void setBombManager(BombManager* bombManager);
    
    virtual void Run();
    void startTicking();
    void explode();
    
    int getDamage();
    int getExplodeTime();
    int getScope();
    
    virtual game::MapObject::Type getType();
    
private:
    int explodeTime;
    int bombScope;
    BombManager* bombManager;
    
    
};
    
}

#endif