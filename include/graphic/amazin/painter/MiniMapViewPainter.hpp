#ifndef MINI_MAP_VIEW_PAINTER_HPP_
#define MINI_MAP_VIEW_PAINTER_HPP_

#include <util/SFMLAmazinResource.hpp>

#include <view/View.hpp>
#include <view/model/MiniMapViewModel.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>



namespace graphic {
namespace amazin {

class MiniMapViewPainter : public SFMLAbstractViewPainter {
public:
	MiniMapViewPainter(view::MiniMapViewModel* model);
    

	virtual void init();
	virtual void update();
    
    
private:
    void allocateMapElementSprites(int mapViewRowsNo, int mapViewColumnsNo);
    
    sf::Sprite*** mapElementSprites;     
    util::SFMLAmazinResource* sfmlAmazinResource;
    
    view::MiniMapViewModel* miniMapViewModel;
    view::MapViewModel* mapViewModel;
    
    int numberOfColumns, numberOfRows;
    int elementWidth, elementHeight;
};

}
}


#endif
