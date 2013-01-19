#ifndef HUD_VIEW_PAINTER_HPP_
#define HUD_VIEW_PAINTER_HPP_

#include <view/View.hpp>
#include <view/model/HUDViewModel.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>

namespace sf {
class String;    
}

namespace graphic {
namespace amazin {

class HUDViewPainter : public SFMLAbstractViewPainter {
public:
	HUDViewPainter(view::HUDViewModel* model);
    
	virtual void init();
	virtual void update();
    

    
    
private:
    void setMoneyValueLabel();
    void setHealthValueLabel();
    
    void setHealthIndicator(int health);    
    sf::Sprite* getHealthIndicatorItem(int health);
    
    
	view::HUDViewModel* hudViewModel;
    sf::Sprite* healthBoxSprite;
    
    sf::String* healthValue;
    sf::String* experienceValue;
};

}
}


#endif
