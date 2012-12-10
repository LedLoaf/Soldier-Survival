#ifndef MINI_MAP_VIEW_MODEL_HPP
#define MINI_MAP_VIEW_MODEL_HPP

#include <util/Util.hpp>
#include <vector>
#include <iostream>

#include <view/View.hpp>

#include "MapViewModel.hpp"

namespace view {

class MiniMapViewModel : public ViewModel {
public:
    
	MiniMapViewModel();
	virtual ~MiniMapViewModel();

    int getNumberOfColumns();
    int getNumberOfRows();
    
    // element na widoczny dla uzytkownika (na samej gorze)
    MapViewModel::Element getTopElementAt(int x, int y);

private:
    
};

} /* namespace view */
#endif
