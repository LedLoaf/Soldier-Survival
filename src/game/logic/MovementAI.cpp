#include <math.h>
#include <time.h>
#include <cstdlib>

#include <game/MovementAI.hpp>

namespace game {

MovementAI::MovementAI(int movingTimeInterval) {
    mapView = ((view::GamePlayWindow) Application.getContext()->getActiveWindow())->getMapView();
    this->movingTimeInterval = movingTimeInterval;
}


int MovementAI::getTimeOfLastMove() {
    return timeOfLastMove;
}

int MovementAI::getMovingTimeInterval() {
    return movingTimeInterval;
}
}