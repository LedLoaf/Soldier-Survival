#ifndef WAR_MANAGER_HPP_
#define WAR_MANAGER_HPP_

#include <view/window/Window.hpp>
#include <util/Resource.hpp>

#include "object/Player.hpp"
#include "object/Enemy.hpp"


namespace game {

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














