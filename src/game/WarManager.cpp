#include <view/window/Window.hpp>
#include <game/Context.hpp>

#include "game/WarManager.hpp"

namespace game {

bool WarManager::isWarAlreadyStartedBetween(Player* player, Enemy* enemy) {
    for (std::vector<War*>::iterator it = existingWars.begin(); it != existingWars.end(); ++it)
        if ((*it)->getEnemy() == enemy)
            return true;
        else
            return false;
}

void WarManager::checkWarsExistance() {
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

void WarManager::startWar(War* war) {
    war->setWarView(warView);
    war->start();

    existingWars.push_back(war);
}

void WarManager::stopWar(War* war) {
    war->stop();

    existingWars.push_back(war);
}

}
