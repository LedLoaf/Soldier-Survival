#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <algorithm>
#include <vector>
#include <map>

namespace graphic {
namespace amazin {

SelectionViewPainter::SelectionViewPainter(view::SelectionViewModel* model) {
	this->selectionModel = model;
    this->selectableElements = model->getSelectableElements();

	init();
}

void SelectionViewPainter::initSelectableSprite(view::SelectionViewModel::SelectableElement& selectableElement) {
//	sprites.insert(std::pair<int, Sprite&>(selectableElement.getId(), new sf::Sprite(selectableElement));
    
//    sf::Sprite* sprite = new sf::Sprite();
//    sprite.Resize(selectionModel->getElementWidth(), selectionModel->getElementHeight());
//    sprite->SetX(selectionModel->getViewPosition().getX());
//    sprite->SetY(selectionModel->getViewPosition().getY());
//    sprite->SetColor(sf::Color::Green);
//    
//    selectableSpritesMap.insert(std::pair<view::SelectionViewModel::SelectableElement*, sf::Sprite*>(selectableElement, sprite));
}

void SelectionViewPainter::updateSelectableSprite(view::SelectionViewModel::SelectableElement* selectableElement) {
//    std::vector::iterator element = std::find(sprites.begin(), sprites.end(), selectableElement);
//    size_t index = std::distance(sprites.begin(), element);
//
//        
//	if (selectableElement.isSelected())
//		sprites[index].setColor(sf::Color::Blue);
//	else
//		sprites[index].setColor(sf::Color::Green);
    // mapa <
    
//    sf::Sprite* selectableSprite = selectableSpritesMap.find(selectableElement)->second;
//    
//    if (selectableElement->isSelected())
//        selectableSprite->SetColor(sf::Color::Blue);
//    else
//        selectableSprite->SetColor(sf::Color::Green);

}


void SelectionViewPainter::init() {
//	std::for_each (selectableElements.begin(), selectableElements.end(), initSelectableSprite);
    
    for(std::vector<view::SelectionViewModel::SelectableElement*>::iterator it = selectableElements.begin(); it != selectableElements.end(); ++it) {
        sf::Sprite* sprite = new sf::Sprite();
        sprite->Resize((*it)->getElementWidth(), (*it)->getElementHeight());
        sprite->SetX(selectionModel->getViewPosition().getX());
        sprite->SetY(selectionModel->getViewPosition().getY());
        sprite->SetColor(sf::Color::Green);

        selectableSpritesMap.insert(std::pair<view::SelectionViewModel::SelectableElement*, sf::Sprite*>(*it, sprite));
    }
}


void SelectionViewPainter::update() {
//	std::for_each (selectableElements.begin(), selectableElements.end(), updateSelectableSprite);

    view::SelectionViewModel::SelectableElement* element;
    
    for(std::vector<view::SelectionViewModel::SelectableElement*>::iterator it = selectableElements.begin(); it != selectableElements.end(); ++it) {
//        element = (view::SelectionViewModel::SelectableElement*) it;
        sf::Sprite* selectableSprite = selectableSpritesMap.find(*it)->second;

        if ((*it)->isSelected())
            selectableSprite->SetColor(sf::Color::Blue);
        else
            selectableSprite->SetColor(sf::Color::Green);
    }    
}

std::vector<sf::Sprite*> SelectionViewPainter::getSprites() {
    std::vector<sf::Sprite*> sprites;
    
    for( std::map<view::SelectionViewModel::SelectableElement*, sf::Sprite*>::iterator it = selectableSpritesMap.begin(); it != selectableSpritesMap.end(); ++it ) {
    	sprites.push_back( it->second );
    }
    
    return sprites;
}


}
}

