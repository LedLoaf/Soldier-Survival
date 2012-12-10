#ifndef MINI_MAP_VIEW_HPP_
#define MINI_MAP_VIEW_HPP_


#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>
#include <util/Location.hpp>

namespace view {

class MiniMapView : public View {
private:
	MapViewModel* mapViewModel;

public:
    MiniMapView(int xStart, int yStart, int xEnd, int yEnd);
    virtual Type getType();

    
    void setMapModel(MapViewModel* mapModel);
    MapViewModel* getModel();
};

}
