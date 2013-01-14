#include <cstddef> //do poprawnej kompilacji SFML //(NULL)
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
    int healthBoxtWidth, healthBoxHeight, moneyBoxtWidth, moneyBoxHeight;
    std::string fontPath;
    int labelsSize;
    int paddingLeft, paddingTop;
    
    healthBoxtWidth = 100;
    healthBoxHeight = 25;
    fontPath = "resource/graphic/amazin/font/magnum.ttf";

    labelsSize = 15;

    paddingLeft = paddingTop = 5;
    
    /* Health */
    
    healthBoxSprite = new sf::Sprite();
    healthBoxSprite->Resize(healthBoxtWidth, healthBoxHeight);
    healthBoxSprite->SetX(hudViewModel->getViewStartPosition()->getX());
    healthBoxSprite->SetY(hudViewModel->getViewStartPosition()->getY());
    healthBoxSprite->SetColor(sf::Color::Green);    
    
    drawables.push_back(healthBoxSprite);

    
    labelsSize = 15;

    sf::Font font;
    if (!font.LoadFromFile(fontPath, 50)) {
        // throw exception. error
    }    


    sf::String* healthLabel = new sf::String();
    healthLabel->SetStyle(sf::String::Bold);
    healthLabel->SetText(std::string("Health:"));
    healthLabel->SetFont(sf::Font::GetDefaultFont());
    healthLabel->SetSize(labelsSize);
    healthLabel->SetX(healthBoxSprite->GetPosition().x);
    healthLabel->SetY(healthBoxSprite->GetPosition().y);

    drawables.push_back(healthLabel);
    
    healthValueLabel = new sf::String();
    healthValueLabel->SetStyle(sf::String::Bold);
    healthValueLabel->SetText(std::string(""));
    healthValueLabel->SetFont(sf::Font::GetDefaultFont());
    healthValueLabel->SetSize(labelsSize);
    healthValueLabel->SetX(healthLabel->GetPosition().x + healthLabel->GetSize() + 30);
    healthValueLabel->SetY(healthLabel->GetPosition().y);

    drawables.push_back(healthValueLabel);        
    
    
    
    /* Money */
    
    moneyBoxtWidth = 100;
    moneyBoxHeight = 25;
    
    sf::Sprite* moneyBoxSprite = new sf::Sprite();
    moneyBoxSprite->Resize(healthBoxtWidth, healthBoxHeight);
    moneyBoxSprite->SetX(healthBoxSprite->GetPosition().x);
    moneyBoxSprite->SetY(healthBoxSprite->GetPosition().y + healthBoxSprite->GetSize().y);
    moneyBoxSprite->SetColor(sf::Color::Magenta);    
    
    drawables.push_back(moneyBoxSprite);
    
    labelsSize = 15;


    sf::String* moneyLabel = new sf::String();
    moneyLabel->SetStyle(sf::String::Bold);
    moneyLabel->SetText(std::string("Money:"));
    moneyLabel->SetFont(sf::Font::GetDefaultFont());
    moneyLabel->SetSize(labelsSize);
    moneyLabel->SetX(moneyBoxSprite->GetPosition().x);
    moneyLabel->SetY(moneyBoxSprite->GetPosition().y);

    drawables.push_back(moneyLabel);    
    
    moneyValueLabel = new sf::String();
    moneyValueLabel->SetStyle(sf::String::Bold);
    moneyValueLabel->SetText(std::string(" "));
    moneyValueLabel->SetFont(sf::Font::GetDefaultFont());
    moneyValueLabel->SetSize(labelsSize);
    moneyValueLabel->SetX(moneyLabel->GetPosition().x + moneyLabel->GetSize() + 30);
    moneyValueLabel->SetY(moneyLabel->GetPosition().y);

    drawables.push_back(moneyValueLabel);     

       
}


void HUDViewPainter::update() {
    setHealthValueLabel();
    setMoneyValueLabel();
}

void HUDViewPainter::setHealthValueLabel() {
    healthValueLabel->SetText(util::Util::toString(hudViewModel->getPlayerHealth()));
}

void HUDViewPainter::setMoneyValueLabel() {
//    moneyValueLabel->SetText(std::string(""));
}

}
}