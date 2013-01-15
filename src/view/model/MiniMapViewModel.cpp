#include <view/model/MiniMapViewModel.hpp>

namespace view {

void MiniMapViewModel::setMapViewModel(view::MapViewModel* mapViewModel) {
    this->mapViewModel = mapViewModel;
}    
    
view::MapViewModel* MiniMapViewModel::getMapViewModel() {
    return mapViewModel;
}


} /* namespace view */
