#include <SFML/System/Sleep.hpp>

#include "game/War.hpp"


namespace game {

War::War(Player* player, Enemy* enemy) {
    this->player = player;
    this->enemy = enemy;
}
 
void War::start() {
    // w osobnym watku odbieranie zycia przeciwnikowi i playerowi + informowanie warView o efektach 
    warExecutor->Launch();
}

void War::stop() {
    // ubij watek
}

void War::setWarView(view::WarView* warView) {
    this->warView = warView;
}

    
Enemy* War::getEnemy() {
    return enemy;
}


Player* War::getPlayer() {
    return player;
}


void War::WarExecutor::Run() {
    playerWeapon = player->getCurrentWeapon();
    enemyWeapon = enemy->getWeapon();

    player->injureUsing(enemyWeapon);
    enemy->injureUsing(playerWeapon);

    // warView->

    sf::Sleep(0.1f);
}

}
