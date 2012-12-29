#include <view/View.hpp>
#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>

#include <util/Location.hpp>

#include "view/MiniMapView.hpp"

namespace view {

MiniMapView::MiniMapView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
}


View::Type MiniMapView::getType() {
    return View::MINI_MAP_VIEW;
}

void MiniMapView::setMapModel(MiniMapViewModel* mapModel) {
    this->mapViewModel = mapModel;
}
    
MiniMapViewModel* MiniMapView::getModel() {
    return this->mapViewModel;
}


}
