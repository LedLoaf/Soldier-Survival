#include <vector>
#include <algorithm>

#include <view/MapView.hpp>
#include <view/WarView.hpp>

#include "game/WarManager.hpp"
#include <game/War.hpp>

namespace game {

WarManager::WarManager() {
    this->shouldCheckWarsExistance = true;
    Launch();
}    

WarManager::~WarManager() {
    shouldCheckWarsExistance = false;
    Terminate();
    // TODO: reszta czyszczenia
}

void WarManager::Run() {
    while(shouldCheckWarsExistance) {
        checkWarsExistance();
    }
}
    
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
        war = *it;
        enemy = war->getEnemy(); 
        player = war->getPlayer();

        if (!mapView->areColliding(player, enemy)) {
            stopWar(war);
            return;
        }

    }
}

void WarManager::startWar(War* war) {
    std::cout << "WarManager::startWar()" << std::endl;
    
    war->start();

    existingWars.push_back(war);
}

void WarManager::stopWar(War* war) {
    war->stop();

    existingWars.erase(std::find(existingWars.begin(), existingWars.end(), war));
    delete war;
}

}
