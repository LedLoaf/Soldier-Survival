#ifndef WAR_MANAGER_HPP_
#define WAR_MANAGER_HPP_

#include <view/window/Window.hpp>
#include <util/Resource.hpp>

#include "object/Player.hpp"
#include "object/Enemy.hpp"


namespace game {

class WarManager {
public:
	void startWar(War* war) {
        war->setWarView(warView);
        war->start();
        
        existingWars.push_back(war);
    }
    
	void stopWar(War* war) {
        war->stop();
        
        existingWars.push_back(war);
    }   
    
    bool isWarAlreadyStartedBetween(Player* player, Enemy* enemy) {
        for (std::vector<War*>::iterator it = existingWars.begin(); it != existingWars.end(); ++it)
            if ((*it)->getEnemy() == enemy)
                return true;
            else
                return false;
    }
    
    void checkWarsExistance() {
        Enemy* enemy;
        Player* player;
        War* war;
        
        for (std::vector<War*>::iterator it = existingWars.begin(); it != existingWars.end(); ++it) {
            war = (*it);
            enemy = war->getEnemy(); 
            player = war->getPlayer();
        
            if (!mapView->areColliding(player, enemy)) {
                stopWar(war);
            }
           
        }
    }
    
    
    
private:
    std::vector<War*> existingWars;
    
    view::MapView* mapView;
    view::WarView* warView;
};

}

#endif














