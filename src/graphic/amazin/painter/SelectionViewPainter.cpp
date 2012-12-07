#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <util/Location.hpp>

#include <algorithm>
#include <vector>
#include <map>

#include <SFML/Graphics/Sprite.hpp>

namespace graphic {
namespace amazin {

SelectionViewPainter::SelectionViewPainter(view::SelectionViewModel* model, view::View::Type parentViewType) {
	this->selectionModel = model;
    this->selectableElements = model->getSelectableElements();
    this->parentViewType = parentViewType;

	init();
}


void SelectionViewPainter::init() {
//	std::for_each (selectableElements.begin(), selectableElements.end(), initSelectableSprite);
    int elementWidth, elementHeight;
    
    if (parentViewType == view::View::MAIN_MENU_WINDOW) {
        elementWidth = 300;
        elementHeight = 50;
        
    }
        
    for (int i = 0; i < selectableElements.size(); i++) {
        sf::Sprite* sprite = new sf::Sprite();
        sprite->Resize(elementWidth, elementHeight);
        sprite->SetX(selectionModel->getViewStartPosition()->getX());
        sprite->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight);
        sprite->SetColor(sf::Color::Green);

        selectableSpritesMap.insert(std::pair<view::SelectionViewModel::SelectableElement*, sf::Sprite*>(selectableElements[i], sprite));
        sprites.push_back(sprite);
    }
}


void SelectionViewPainter::update() {
//	std::for_each (selectableElements.begin(), selectableElements.end(), updateSelectableSprite);

    view::SelectionViewModel::SelectableElement* element;
    
    for(std::vector<view::SelectionViewModel::SelectableElement*>::iterator it = selectableElements.begin(); it != selectableElements.end(); ++it) {
//        element = (view::SelectionViewModel::SelectableElement*) it;
        sf::Sprite* selectableSprite = selectableSpritesMap.find(*it)->second;

        if ((*it)->isSelected())
            selectableSprite->SetColor(sf::Color::Red);
        else
            selectableSprite->SetColor(sf::Color::Green);
    }    
}


}
}