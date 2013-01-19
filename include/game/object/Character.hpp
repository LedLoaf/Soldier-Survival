#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/System/Thread.hpp>

#include <util/Location.hpp>
#include <game/object/MapObject.hpp>


namespace view {
class MapViewModel;
class MapView;
}

namespace game {

class CharacterLife;    
class MovementAI;
class Weapon;
    
class Character : public MapObject {
public:
    Character(MapObject::Type type, view::MapViewModel* mapViewModel);
    ~Character();
    
    void setPosition(util::Location::Position pos);
    util::Location::Position getPosition();
    
    view::MapViewModel* getMapModel();
    view::MapView* getMapView();
    
    void beginLife();
    void pauseLife();
    void resumeLife();
    void endLife();
    
    void setHealth(int health);
    int getHealth();    
    
    virtual void injureUsing(Weapon* weapon);
    
protected:
    view::MapView* mapView;
    view::MapViewModel* mapViewModel;
    CharacterLife* life;
    util::Location::Position position;
    int health;
    
};
    
}

#endif