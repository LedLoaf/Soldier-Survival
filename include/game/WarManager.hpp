#ifndef WAR_MANAGER_HPP_
#define WAR_MANAGER_HPP_

#include <vector>

namespace view {
class MapView;  
class WarView;
}

namespace game {

class War;
class Player;
class Enemy;

class WarManager {
public:
	void startWar(War* war);
    void stopWar(War* war);
   
    bool isWarAlreadyStartedBetween(Player* player, Enemy* enemy);
    
    void checkWarsExistance();

    
    
private:
    std::vector<War*> existingWars;
    
    view::MapView* mapView;
    view::WarView* warView;
};

}

#endif














