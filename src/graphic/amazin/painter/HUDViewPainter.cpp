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
    int margin = 5;
    int labelsTextSize = 20;
    
    // health 
    
    sf::String* healthLabel = new sf::String();
    healthLabel->SetText("Health");
    healthLabel->SetFont(sf::Font::GetDefaultFont());
    healthLabel->SetSize(labelsTextSize);
    healthLabel->SetX(hudViewModel->getViewStartPosition()->getX());
    healthLabel->SetY(hudViewModel->getViewStartPosition()->getY());    

    drawables.push_back(healthLabel);    
    
    healthValue = new sf::String();
    healthValue->SetStyle(sf::String::Bold);
    healthValue->SetColor(sf::Color::Red);    
    healthValue->SetText("70");
    healthValue->SetFont(sf::Font::GetDefaultFont());
    healthValue->SetSize(labelsTextSize);
    healthValue->SetX(hudViewModel->getViewStartPosition()->getX());
    healthValue->SetY(hudViewModel->getViewStartPosition()->getY() + labelsTextSize + margin);    

    drawables.push_back(healthValue);        
    
    // money 
    
    sf::String* experienceLabel = new sf::String();
    experienceLabel->SetText("Experience");
    experienceLabel->SetFont(sf::Font::GetDefaultFont());
    experienceLabel->SetSize(labelsTextSize);
    experienceLabel->SetX(hudViewModel->getViewStartPosition()->getX());
    experienceLabel->SetY(healthValue->GetPosition().y + labelsTextSize + margin);    

    drawables.push_back(experienceLabel);    
    
    
    experienceValue = new sf::String();
    experienceValue->SetStyle(sf::String::Bold);
    experienceValue->SetColor(sf::Color::Yellow);
    experienceValue->SetText("553");
    experienceValue->SetFont(sf::Font::GetDefaultFont());
    experienceValue->SetSize(labelsTextSize);
    experienceValue->SetX(hudViewModel->getViewStartPosition()->getX());
    experienceValue->SetY(experienceLabel->GetPosition().y + labelsTextSize + margin);    

    drawables.push_back(experienceValue);         
    
}


void HUDViewPainter::update() {
    setHealthValueLabel();
    setMoneyValueLabel();
}

void HUDViewPainter::setHealthValueLabel() {
    healthValue->SetText(util::Util::toString(hudViewModel->getPlayerHealth()));
}

void HUDViewPainter::setMoneyValueLabel() {
    experienceValue->SetText(util::Util::toString(hudViewModel->getPlayerExperiencePoints()));
}

}
}