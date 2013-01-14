#include <math.h>
#include <time.h>
#include <cstdlib>

#include <SFML/System/Sleep.hpp>

#include "game/logic/EnemyLife.hpp"
#include "game/Application.hpp"
#include "view/window/GamePlayWindow.hpp"
#include <game/logic/CharacterLife.hpp>
#include <game/logic/MovementAI.hpp>
#include <game/logic/EnemyMovementAI.hpp>

#include <util/Util.hpp>

namespace game {

EnemyLife::EnemyLife(Character* ch, int timeOfBirth, int lifetime, EnemyMovementAI* movementAI) : CharacterLife(ch, timeOfBirth, lifetime) {
    this->movementAI = movementAI;
}

void EnemyLife::Run() {
    while (stillAlive) {
//        if (isTimeToMove()) {
            movementAI->tryToDoNextMove();

//        }

        
        if (isTimeToDie()) {

        }
            
        sf::Sleep(0.8f);            
    }

    // die
    // do poprawy takie branie wskaznika do map view
    view::MapView* mapView = dynamic_cast<view::GamePlayWindow*>(game::Application::getInstance().getContext()->getActiveWindow())->getMapView();
    mapView->showDeathOf(character);
    
    sf::Sleep(3);
    
    mapView->buryCharacter(character);
}

bool EnemyLife::isTimeToMove() {
    if ((util::Util::getCurrentTime() - movementAI->getTimeOfLastMove()) > movementAI->getMovingTimeInterval())
        return true;
    else
        return false;
}


}