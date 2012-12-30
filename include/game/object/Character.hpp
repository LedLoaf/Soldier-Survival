#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <util/Location.hpp>

#include <game/object/MapObject.hpp>

namespace game {
    
class Character : public MapObject {
public:

    void setPosition(util::Location::Position pos);
    util::Location::Position getPosition();
    
    virtual void startLife();
    
    
protected:
    
    class Life : public sf::Thread {
    public:
        Life(int timeOfBirth, int lifetime);
        virtual void Run();
        
        bool isTimeToMove();
        bool isTimeToDie();
        
    protected:
           
        int lifetime; // -1 oznacza, ze zyje dopuki nie zostanie zabity
        int timeOfBirth;
 
    };
    
    Life* life;
    util::Location::Position position;
    view::MapView* mapView;
    MovementAI* movementAI;
    
};
    
}

#endif