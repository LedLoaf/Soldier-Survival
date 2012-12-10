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

#include "view/SelectionView.hpp"
#include <game/object/weapon/Weapon.hpp>

namespace graphic {
namespace amazin {

SelectionViewPainter::SelectionViewPainter(view::SelectionViewModel* model) {
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
    
    switch (selectionModel->getType()) {
        case view::SelectionViewModel::SIMPLE_MENU :
            elementWidth = 300;
            elementHeight = 50;
            fontPath = "resource/graphic/amazin/font/magnum.ttf";

            textSize = 20;

            paddingLeft = paddingTop = 5;
            break;
            
        case view::SelectionViewModel::WEAPONS :
            elementWidth = 300;
            elementHeight = 20;
            fontPath = "resource/graphic/amazin/font/magnum.ttf";
            
            textSize = 10;
            

            paddingLeft = paddingTop = 5;
            break;            
    }
 
    for (int i = 0; i < selectableElements.size(); i++) {
        sf::Sprite* sprite = new sf::Sprite();
        sprite->Resize(elementWidth, elementHeight);
        sprite->SetX(selectionModel->getViewStartPosition()->getX());
        sprite->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight);
        sprite->SetColor(sf::Color::Green);
     
        selectableSpritesMap.insert(std::pair<view::SelectionViewModel::SelectableElement*, sf::Sprite*>(selectableElements[i], sprite));
        drawables.push_back(sprite);     
        
        
        
        if (selectionModel->getType() == view::SelectionViewModel::SIMPLE_MENU) {
            sf::String* text = new sf::String();
            text->SetText(getTextFor(selectableElements[i]->getAction()));
            // przy text->SetFont(font) segmentation fault - cos zle z plikeim ttf
            text->SetFont(sf::Font::GetDefaultFont());
            text->SetSize(textSize);
            text->SetX(selectionModel->getViewStartPosition()->getX() + paddingLeft);
            text->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight + paddingTop);    

            drawables.push_back(text);

        } else if (selectionModel->getType() == view::SelectionViewModel::WEAPONS) {
                view::SelectionViewModel::WeaponSelectableElement* weaponElement = 
                        dynamic_cast<view::SelectionViewModel::WeaponSelectableElement*>(selectableElements[i]);

                
                /* weapon image */
                
                std::string imgPath;
                
                switch (weaponElement->getWeapon()->getType()) {
                    case game::Weapon::KNIFE :
                        imgPath = "resource/graphic/amazin/game_play/img/weapon/knife.jpg";
                }

                // wskaznik, bo inaczej zostanie zniszczony
                // w destruktorze niszczyc
                sf::Image* image = new sf::Image();
                if (!image->LoadFromFile(imgPath)) {
                    std::cout << "Failed to load " << imgPath << std::endl;
                }

                sf::Sprite* weaponImgSprite = new sf::Sprite;
                weaponImgSprite->SetX(selectionModel->getViewStartPosition()->getX() + paddingLeft);
                weaponImgSprite->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight + paddingTop);    
                weaponImgSprite->SetImage(*image);
                
                drawables.push_back(weaponImgSprite);
                
                /* weapon damage */
                
                sf::String* text = new sf::String();
                text->SetText(util::Util::toString(weaponElement->getWeapon()->getDamage()));
                // przy text->SetFont(font) segmentation fault - cos zle z plikeim ttf
                text->SetFont(sf::Font::GetDefaultFont());
                text->SetSize(textSize);
                text->SetX(selectionModel->getViewStartPosition()->getX() + weaponImgSprite->GetSize().x + 10);
                text->SetY(selectionModel->getViewStartPosition()->getY() + i * elementHeight + paddingTop);    

                drawables.push_back(text);                
        }        
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

std::string SelectionViewPainter::getTextFor(util::Util::Action action) {
    switch (action) {
        case util::Util::RUN_LEVEL_SELECTION :
            return "level selection";
        case util::Util::RUN_ABOUT :
            return "about";
        case util::Util::RUN_EXIT :
            return "exit"; 
        case util::Util::RUN_GAME_PLAY :
            return "play";             
        default:
            return "";
    }
}



}
}