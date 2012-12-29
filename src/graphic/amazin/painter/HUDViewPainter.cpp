#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <util/Location.hpp>
#include <util/Util.hpp>

#include <algorithm>
#include <vector>
#include <map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/String.hpp>

#include <graphic/amazin/painter/HUDViewPainter.hpp>

namespace graphic {
namespace amazin {

HUDViewPainter::HUDViewPainter(view::HUDViewModel* model) {
	this->hudViewModel = model;

	init();
}


void HUDViewPainter::init() {
    int healthBoxtWidth, healthBoxHeight;
    std::string fontPath;
    int textSize;
    int paddingLeft, paddingTop;
    
    healthBoxtWidth = 100;
    healthBoxHeight = 50;
    fontPath = "resource/graphic/amazin/font/magnum.ttf";

    textSize = 20;

    paddingLeft = paddingTop = 5;
    
    /* Health */
    
    healthBoxSprite = new sf::Sprite();
    healthBoxSprite->Resize(healthBoxtWidth, healthBoxHeight);
    healthBoxSprite->SetX(hudViewModel->getViewStartPosition()->getX());
    healthBoxSprite->SetY(hudViewModel->getViewStartPosition()->getY());
    healthBoxSprite->SetColor(sf::Color::Green);    
    
    drawables.push_back(healthBoxSprite);
    
    for (int i = 0; i < 10; i++)
        healthIndicatorSprites.push_back(getHealthIndicatorItem(i));
    
    /* Experience */
    
    sf::Sprite* experienceBoxSprite = new sf::Sprite();
    experienceBoxSprite->Resize(healthBoxtWidth, healthBoxHeight);
    experienceBoxSprite->SetX(healthBoxSprite->GetPosition().x);
    experienceBoxSprite->SetY(healthBoxSprite->GetPosition().y + healthBoxSprite->GetSize().y);
    experienceBoxSprite->SetColor(sf::Color::Cyan);    
    
    drawables.push_back(experienceBoxSprite);   
    
    
    
//    sf::Font font;
//    if (!font.LoadFromFile(fontPath, 50)) {
//        // throw exception. error
//    }    


//        sf::String* text = new sf::String();
//        text->SetText(getTextFor(selectableElements[i]->getAction()));
//        // przy text->SetFont(font) segmentation fault - cos zle z plikeim ttf
//        text->SetFont(sf::Font::GetDefaultFont());
//        text->SetSize(textSize);
//        text->SetX(selectionModel->getViewStartPosition()->getX() + paddingLeft);
//        text->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight + paddingTop);


       
}


void HUDViewPainter::update() {
//	std::for_each (selectableElements.begin(), selectableElements.end(), updateSelectableSprite);
    
//    for(std::vector<view::SelectionViewModel::SelectableElement*>::iterator it = selectableElements.begin(); it != selectableElements.end(); ++it) {
////        element = (view::SelectionViewModel::SelectableElement*) it;
//        sf::Sprite* selectableSprite = selectableSpritesMap.find(*it)->second;
//
//        if ((*it)->isSelected())
//            selectableSprite->SetColor(sf::Color::Red);
//        else
//            selectableSprite->SetColor(sf::Color::Green);
//    }    
    
//    int health = hudViewModel->getPlayerHealth();
    int health = 2;
    
    setHealthIndicator(health);
}

void HUDViewPainter::setHealthIndicator(int health) {
    // TODO: MAX_PLAYER_HEALTH brane z Player
    int currentHealth = healthIndicatorSprites.size();
    
    if (currentHealth > health) {
        for (int i = currentHealth - health; i > 0; i--) {
            healthIndicatorSprites.pop_back();
        }
    } else {
        for (int i = health - currentHealth; i > 0; i--) 
            healthIndicatorSprites.push_back(getHealthIndicatorItem(health));
    }
}

sf::Sprite* HUDViewPainter::getHealthIndicatorItem(int health) {
    int indicatorWidth = 5;
    int indicatorHeight = 20;
    
    sf::Sprite* redIndicatorSprite = new sf::Sprite();
    redIndicatorSprite->Resize(indicatorWidth, indicatorHeight);
    redIndicatorSprite->SetX(healthBoxSprite->GetPosition().x + indicatorWidth);
    redIndicatorSprite->SetY(healthBoxSprite->GetPosition().y);
    redIndicatorSprite->SetColor(sf::Color::Red);     
    
    sf::Sprite* yellow2IndicatorSprite = new sf::Sprite();
    yellow2IndicatorSprite->Resize(indicatorWidth, indicatorHeight);
    yellow2IndicatorSprite->SetX(healthBoxSprite->GetPosition().x + indicatorWidth * 2);
    yellow2IndicatorSprite->SetY(healthBoxSprite->GetPosition().y);
    yellow2IndicatorSprite->SetColor(sf::Color::Yellow);       
    
    switch (health) {
        case 1:
            return redIndicatorSprite;
        default:
            return yellow2IndicatorSprite;
    }
}


std::string HUDViewPainter::getTextFor(util::Util::Action action) {
    switch (action) {
        case util::Util::RUN_LEVEL_SELECTION :
            return "level selection";
        case util::Util::RUN_ABOUT :
            return "about";
        case util::Util::RUN_EXIT :
            return "exit";            
        default:
            return "";
    }
}

std::vector<sf::Drawable*> HUDViewPainter::getDrawables() {
    int size = healthIndicatorSprites.size();
    drawables.insert(drawables.end(), healthIndicatorSprites.begin(), healthIndicatorSprites.end());

    
	return drawables;
}

}
}