#ifndef MINI_MAP_VIEW_HPP_
#define MINI_MAP_VIEW_HPP_


#include <view/View.hpp>
#include <view/model/MiniMapViewModel.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>
#include <util/Location.hpp>

namespace view {

class MiniMapView : public View {
private:
	MiniMapViewModel* mapViewModel;

public:
    MiniMapView(int xStart, int yStart, int xEnd, int yEnd);
    virtual Type getType();

    
    void setMapModel(MiniMapViewModel* mapModel);
    MiniMapViewModel* getModel();
};



}

#endif
