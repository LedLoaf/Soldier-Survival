#ifndef MOVEMENT_AI_HPP_
#define MOVEMENT_AI_HPP_



namespace game {
    
class MovementAI {
public:
    MovementAI(int movingTimeInterval);
    
    virtual void tryToDoNextMove() = 0;
    virtual void doNextMove(); // ewentualnie potem rozdzielic logike z tryToDoNextMove tutaj
    
    int getTimeOfLastMove();
    int getMovingTimeInterval();
    
protected:
    view::MapView* mapView;
    int timeOfLastMove;
    int movingTimeInterval;
};

}

#endif

