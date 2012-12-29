#ifndef MOVEMENT_AI_HPP_
#define MOVEMENT_AI_HPP_



namespace game {
    
class MovementAI {
public:
    MovementAI() {
        mapView = ((view::GamePlayWindow) Application.getContext()->getActiveWindow())->getMapView();
    }
    virtual void move() = 0;
protected:
    view::MapView* mapView;
};

}

#endif

