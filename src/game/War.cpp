#include <view/window/Window.hpp>
#include <game/Context.hpp>

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


void War::WarExecutor::Run() {
    playerWeapon = player->getCurrentWeapon();
    enemyWeapon = enemy->getWeapon();

    player->injureUsing(enemyWeapon);
    enemy->injureUsing(playerWeapon);

    // warView->

    sf::Sleep(0.1f);
}


}
