#ifndef CHARACTER_LIFE_HPP_
#define CHARACTER_LIFE_HPP_

#include <SFML/System/Thread.hpp>

namespace game {

class Character;    
    
class CharacterLife : public sf::Thread {
public:
    CharacterLife(Character* ch, int timeOfBirth, int lifetime);

    virtual void Run() = 0;

    void die();
    
protected:
    Character* character;
    int lifetime; // -1 oznacza, ze zyje dopuki nie zostanie zabity
    int timeOfBirth;
    bool stillAlive;

    bool isTimeToDie();
};

}

#endif

