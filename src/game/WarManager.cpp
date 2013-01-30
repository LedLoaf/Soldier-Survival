#include <vector>
#include <algorithm>

#include <SFML/System/Mutex.hpp>
#include <SFML/System/Sleep.hpp>

#include <view/MapView.hpp>
#include <view/WarView.hpp>

#include "game/WarManager.hpp"
#include <game/War.hpp>

namespace game {

WarManager::WarManager(view::MapView* mapView) {
    this->mapView = mapView;
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
        GlobalMutex.Lock();
        checkWarsExistance();
        GlobalMutex.Unlock();
        
        sf::Sleep(0.01f);
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
            mapView->stopWar(war);
            return;
        }

    }
}

void WarManager::startWar(War* war) {
//    std::cout << "WarManager::startWar()" << std::endl;
    
    war->start();
    
    GlobalMutex.Lock();
    existingWars.push_back(war);
    GlobalMutex.Unlock();
}

void WarManager::stopWar(War* war) {
    war->stop();

    stopWarMutex.Lock();
    existingWars.erase(std::find(existingWars.begin(), existingWars.end(), war));
    delete war;
    stopWarMutex.Unlock();
}

void WarManager::stopAllWars() {
    for (int i = 0; i < existingWars.size(); i++)
        existingWars[i]->stop();
}

}
