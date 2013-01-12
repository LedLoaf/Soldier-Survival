#ifndef CHARACTER_LIFE_HPP_
#define CHARACTER_LIFE_HPP_

#include <SFML/System/Thread.hpp>

namespace game {
    
class CharacterLife : public sf::Thread {
public:
    CharacterLife(int timeOfBirth, int lifetime);

    virtual void Run() = 0;

protected:
    int lifetime; // -1 oznacza, ze zyje dopuki nie zostanie zabity
    int timeOfBirth;
    bool stillAlive;

    bool isTimeToDie();
};

}

#endif

