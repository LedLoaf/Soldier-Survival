#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/System/Thread.hpp>

#include <util/Location.hpp>
#include <game/object/MapObject.hpp>


namespace view {
    class MapView;
}

namespace game {

class CharacterLife;    
class MovementAI;
class Weapon;
    
class Character : public MapObject {
public:
    Character(MapObject::Type type);
    
    void setPosition(util::Location::Position pos);
    util::Location::Position getPosition();
    
    void beginLife();
   
    void setHealth(int health);
    int getHealth();    
    

    virtual void injureUsing(Weapon* weapon);
    
protected:
    
    CharacterLife* life;
    util::Location::Position position;
    view::MapView* mapView;
    MovementAI* movementAI;
    
    int health;
    
};
    
}

#endif