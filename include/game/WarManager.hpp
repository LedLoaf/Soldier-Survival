#ifndef WAR_MANAGER_HPP_
#define WAR_MANAGER_HPP_

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <vector>

namespace view {
class MapView;  
class WarView;
}

namespace game {

class War;
class Player;
class Enemy;

class WarManager : public sf::Thread {
public:
    WarManager(view::MapView* mapView);
    ~WarManager();
	void startWar(War* war);
    void stopWar(War* war);
   
    bool isWarAlreadyStartedBetween(Player* player, Enemy* enemy);
    
    void checkWarsExistance();

    
    
private:
    virtual void Run();    

    std::vector<War*> existingWars;
    
    view::MapView* mapView;
    view::WarView* warView;
    bool shouldCheckWarsExistance;
    sf::Mutex GlobalMutex;
    sf::Mutex stopWarMutex;
    

};

}

#endif














