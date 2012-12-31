#ifndef MINI_MAP_VIEW_MODEL_HPP
#define MINI_MAP_VIEW_MODEL_HPP

#include <vector>
#include <iostream>

namespace game {
    class MapObject;
}

#include <view/View.hpp>
#include <util/Util.hpp>


namespace view {

class MiniMapViewModel : public ViewModel {
public:
    
	MiniMapViewModel();
	virtual ~MiniMapViewModel();

    int getNumberOfColumns();
    int getNumberOfRows();
    
    // element na widoczny dla uzytkownika (na samej gorze)
    game::MapObject* getVisibleMapObject(int x, int y); 
    game::MapObject* getVisibleMapObject(util::Location::Position position); 

private:
    
};

} /* namespace view */
#endif
