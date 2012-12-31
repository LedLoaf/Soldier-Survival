#ifndef WAR_HPP_
#define WAR_HPP_

#include <view/window/Window.hpp>
#include <util/Resource.hpp>

#include <view/WarView.hpp>
#include "object/Player.hpp"
#include "object/Enemy.hpp"



namespace game {

class War {
public:
	War(Player* player, Enemy* enemy);

    
    Enemy* getEnemy();
    Player* getPlayer();
    
    void setWarView(view::WarView* warView);

    

    void start();
    void stop();
    
    
private:
    class WarExecutor : public sf::Thread {
    private:
        virtual void Run();
        
        Weapon* playerWeapon;
        Weapon* enemyWeapon;
        Player* player;
        Enemy* enemy;        
    };    

	view::Window* activeWindow;

    WarExecutor* warExecutor;
    view::WarView* warView;
    Player* player;
    Enemy* enemy;      
    

};

}

#endif














