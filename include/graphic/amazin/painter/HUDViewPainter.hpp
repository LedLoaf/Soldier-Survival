#ifndef HUD_VIEW_PAINTER_HPP_
#define HUD_VIEW_PAINTER_HPP_

#include <view/View.hpp>
#include <view/model/HUDViewModel.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace graphic {
namespace amazin {

class HUDViewPainter : public SFMLAbstractViewPainter {
public:
	HUDViewPainter(view::HUDViewModel* model);
    

	virtual void init();
	virtual void update();
    virtual std::vector<sf::Drawable*> getDrawables();
    
    std::string getTextFor(util::Util::Action action);

    
    
private:
    void setHealthIndicator(int health);    
    sf::Sprite* getHealthIndicatorItem(int health);
    
    
	view::HUDViewModel* hudViewModel;

    sf::Sprite* healthBoxSprite;
    
    std::vector<sf::Drawable*> healthIndicatorSprites;
    
};

}
}


#endif
