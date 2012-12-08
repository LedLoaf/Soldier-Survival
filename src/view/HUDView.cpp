#include <view/HUDView.hpp>
#include <util/Location.hpp>

namespace view {

HUDView::HUDView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {   
    hudViewModel = new HUDViewModel();
    hudViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
}    

void HUDView::setHUDModel(HUDViewModel* hudViewModel) { 
    this->hudViewModel = hudViewModel;
}

HUDViewModel* HUDView::getModel() {
    return this->hudViewModel;
}

View::Type HUDView::getType() {
    return view::View::HUD_VIEW;
}

}