#include <math.h>
#include <time.h>
#include <cstdlib>

#include <game/Application.hpp>
#include <game/logic/MovementAI.hpp>
#include <view/window/GamePlayWindow.hpp>
#include <view/MapView.hpp>


namespace game {

MovementAI::MovementAI(int movingTimeInterval) {
    mapView = (dynamic_cast<view::GamePlayWindow*>(game::Application::getInstance().getContext()->getActiveWindow()))->getMapView();
    this->movingTimeInterval = movingTimeInterval;
}


int MovementAI::getTimeOfLastMove() {
    return timeOfLastMove;
}

int MovementAI::getMovingTimeInterval() {
    return movingTimeInterval;
}


}