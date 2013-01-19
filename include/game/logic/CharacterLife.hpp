#ifndef CHARACTER_LIFE_HPP_
#define CHARACTER_LIFE_HPP_

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>

namespace game {

class Character;    
    
class CharacterLife : public sf::Thread {
public:
    CharacterLife(Character* ch, int timeOfBirth, int lifetime);

    virtual void Run();
    virtual void pause();
    virtual void resume();

    void die();
    
protected:
    Character* character;
    int lifetime; // -1 oznacza, ze zyje dopuki nie zostanie zabity
    int timeOfBirth;
    bool stillAlive;
    bool isPaused;
    sf::Mutex pauseMutex;

    bool isTimeToDie();
};

}

#endif

