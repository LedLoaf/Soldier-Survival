#include <math.h>
#include <time.h>
#include <cstdlib>

#include <util/Util.hpp>
#include <game/Application.hpp>
#include <game/logic/MovementAI.hpp>
#include <view/window/GamePlayWindow.hpp>
#include <view/MapView.hpp>


namespace game {

MovementAI::MovementAI(int movingTimeInterval) {
    this->movingTimeInterval = movingTimeInterval;
    this->timeOfLastMove = util::Util::getCurrentTime();
}


int MovementAI::getTimeOfLastMove() {
    return timeOfLastMove;
}

int MovementAI::getMovingTimeInterval() {
    return movingTimeInterval;
}


}