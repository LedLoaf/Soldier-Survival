#ifndef MINI_MAP_VIEW_PAINTER_HPP_
#define MINI_MAP_VIEW_PAINTER_HPP_

#include <view/View.hpp>
#include <view/model/HUDViewModel.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace graphic {
namespace amazin {

class MiniMapViewPainter : public SFMLAbstractViewPainter {
public:
	MiniMapViewPainter(view::MiniMapViewModel* model);
    

	virtual void init();
	virtual void update();
    virtual std::vector<sf::Drawable*> getDrawables();
    
    
private:
    view::MiniMapViewModel* miniMapViewModel;
    sf::Sprite** map;
    int numberOfColumns, numberOfRows;
    float viewWidth, elementWidth;
};

}
}


#endif
