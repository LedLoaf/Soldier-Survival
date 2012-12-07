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
    std::string fontPath;
    int textSize;
    int paddingLeft, paddingTop;
    
    if (parentViewType == view::View::MAIN_MENU_WINDOW) {
        elementWidth = 300;
        elementHeight = 50;
        fontPath = "resource/graphic/amazin/font/magnum.ttf";
            
        textSize = 20;
        
        paddingLeft = paddingTop = 5;
    }
    
    
//    sf::Font font;
//    if (!font.LoadFromFile(fontPath, 50)) {
//        // throw exception. error
//    }    
        
    for (int i = 0; i < selectableElements.size(); i++) {
        sf::Sprite* sprite = new sf::Sprite();
        sprite->Resize(elementWidth, elementHeight);
        sprite->SetX(selectionModel->getViewStartPosition()->getX());
        sprite->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight);
        sprite->SetColor(sf::Color::Green);


        sf::String* text = new sf::String();
        text->SetText(getTextFor(selectableElements[i]->getAction()));
        // przy text->SetFont(font) segmentation fault - cos zle z plikeim ttf
        text->SetFont(sf::Font::GetDefaultFont());
        text->SetSize(textSize);
        text->SetX(selectionModel->getViewStartPosition()->getX() + paddingLeft);
        text->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight + paddingTop);


        selectableSpritesMap.insert(std::pair<view::SelectionViewModel::SelectableElement*, sf::Sprite*>(selectableElements[i], sprite));
        drawables.push_back(sprite);
        drawables.push_back(text);
        
        
    }
}


void SelectionViewPainter::update() {
//	std::for_each (selectableElements.begin(), selectableElements.end(), updateSelectableSprite);
    
    for(std::vector<view::SelectionViewModel::SelectableElement*>::iterator it = selectableElements.begin(); it != selectableElements.end(); ++it) {
//        element = (view::SelectionViewModel::SelectableElement*) it;
        sf::Sprite* selectableSprite = selectableSpritesMap.find(*it)->second;

        if ((*it)->isSelected())
            selectableSprite->SetColor(sf::Color::Red);
        else
            selectableSprite->SetColor(sf::Color::Green);
    }    
}

std::string SelectionViewPainter::getTextFor(Util::Action action) {
    switch (action) {
        case Util::RUN_LEVEL_SELECTION :
            return "level selection";
        case Util::RUN_ABOUT :
            return "about";
        case Util::RUN_EXIT :
            return "exit";            
        default:
            return "";
    }
}



}
}