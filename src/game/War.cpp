#include <SFML/System/Sleep.hpp>

#include "game/War.hpp"
#include <view/View.hpp>

namespace game {
    
bool War::warIsHappening;    

War::War(Player* player, Enemy* enemy) {
    this->player = player;
    this->enemy = enemy;
    this->warExecutor = new WarExecutor(this);
    
    initWarModel();
    
}

War::~War() {
    view::View* view = warView;
    warView = NULL;
    delete view;    
}

void War::initWarModel() {
    warViewModel = new view::WarViewModel();
    warViewModel->setPlayer(player);
    warViewModel->setEnemy(enemy);
}

view::WarViewModel* War::getWarModel() {
    return warViewModel;
}
 
void War::start() {
    warIsHappening = true;
    warExecutor->Launch();
}

void War::stop() {
    warIsHappening = false;
    warExecutor->Terminate();
}

void War::setWarView(view::WarView* warView) {
    this->warView = warView;
}

view::WarView* War::getWarView() {
    return warView;
}
    
Enemy* War::getEnemy() {
    return enemy;
}


Player* War::getPlayer() {
    return player;
}

War::WarExecutor::WarExecutor(War* war) {
    this->war = war;
}

void War::WarExecutor::Run() {
    while (warIsHappening) {
        war->getPlayer()->injureUsing(war->getEnemy()->getWeapon());

        if (war->getPlayer()->hasAnyWeapons())
            war->getEnemy()->injureUsing(war->getPlayer()->getCurrentWeapon());



        sf::Sleep(0.1f);
    }
}

}
