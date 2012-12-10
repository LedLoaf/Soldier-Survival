#ifndef MINI_MAP_VIEW_MODEL_HPP
#define MINI_MAP_VIEW_MODEL_HPP

#include <util/Util.hpp>
#include <vector>
#include <iostream>

#include <view/View.hpp>

namespace view {

class MiniMapViewModel : public ViewModel {
public:
    enum Element {
        PLAYER, ENEMY_SHOOTER, ENEMY_ABC, GREEN_GRASS, YELLOW_GRASS, RIVER
    };
    
	MiniMapViewModel();
	virtual ~MiniMapViewModel();
    
    // element na widoczny dla uzytkownika (na samej gorze)
    Element getTopElementAt(int x, int y);

private:
    
};

} /* namespace view */
#endif
