#ifndef WAR_VIEW_PAINTER_HPP_
#define WAR_VIEW_PAINTER_HPP_


#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/WarViewModel.hpp>

namespace sf {
    class Sprite;
}

namespace graphic {
namespace amazin {

class WarViewPainter : public SFMLAbstractViewPainter {
public:
	WarViewPainter(view::WarViewModel* warViewModel);
    
	virtual void init();
	virtual void update();
    
private:
    view::WarViewModel* warViewModel;
    sf::Sprite* enemyHealthIndicator;
};

}
}


#endif
