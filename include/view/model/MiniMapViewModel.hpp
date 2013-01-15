#ifndef MINI_MAP_VIEW_MODEL_HPP
#define MINI_MAP_VIEW_MODEL_HPP

#include <vector>
#include <iostream>

namespace game {
    class MapObject;
}

#include <view/View.hpp>
#include <util/Util.hpp>

#include "MapViewModel.hpp"


namespace view {

class MiniMapViewModel : public ViewModel {
public:
    void setMapViewModel(view::MapViewModel* mapViewModel);
    view::MapViewModel* getMapViewModel();

private:
    MapViewModel* mapViewModel;
};

} /* namespace view */
#endif
