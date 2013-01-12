#ifndef WAR_HPP_
#define WAR_HPP_

#include <view/window/Window.hpp>
#include <util/Resource.hpp>

#include <view/WarView.hpp>
#include <view/model/WarViewModel.hpp>
#include "object/Player.hpp"
#include "object/Enemy.hpp"


namespace game {

class War {
public:
	War(Player* player, Enemy* enemy);
    ~War();
    
    Enemy* getEnemy();
    Player* getPlayer();
    
    void setWarView(view::WarView* warView);
    view::WarViewModel* getWarModel();
    

    void start();
    void stop();
    
    
private:
    void initWarModel();
    
    class WarExecutor : public sf::Thread {
    public:
        WarExecutor(War* war);
    private:
        virtual void Run();
        
        War* war;
    };    

    friend class warExecutor;
    
	view::Window* activeWindow;
    view::WarViewModel* warViewModel;
    
    WarExecutor* warExecutor;
    view::WarView* warView;
    Player* player;
    Enemy* enemy;      
    

};

}

#endif














