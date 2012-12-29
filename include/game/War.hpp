#ifndef WAR_HPP_
#define WAR_HPP_

#include <view/window/Window.hpp>
#include <util/Resource.hpp>

#include "object/Player.hpp"
#include "object/Enemy.hpp"


namespace game {

class War {
public:
	void War(Player* player, Enemy* enemy) {
        this->player = player;
        this->enemy = enemy;
    }
    
    Enemy* getEnemy();
    Player* getPlayer();
    
    void setWarView(view::WarView* warView);

    
    void start() {
        // w osobnym watku odbieranie zycia przeciwnikowi i playerowi + informowanie warView o efektach 
    }
    
    void stop();
    
    
private:
	view::Window* activeWindow;
    Player* player;
    Enemy* enemy;
};

}

#endif














