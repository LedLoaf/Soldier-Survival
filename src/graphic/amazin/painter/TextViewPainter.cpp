#include <graphic/amazin/painter/TextViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/String.hpp>

#include "util/Resource.hpp"
#include "view/TextView.hpp"
#include "view/model/TextViewModel.hpp"

#include <string>
#include <iostream>

namespace graphic {
namespace amazin {


TextViewPainter::TextViewPainter(view::TextViewModel* textViewModel) {
    this->textModel = textViewModel;
    
    init();
}
    

void TextViewPainter::init() {    
    std::string fontPath;
    int textSize;
    int paddingLeft, paddingTop;
    
    switch (textModel->getTextViewType()) {
        case view::TextView::SMALL :
            fontPath = "resource/graphic/amazin/font/magnum.ttf";

            textSize = 10;

            paddingLeft = paddingTop = 5;
            break;
    }

    
    sf::String* text = new sf::String();
    text->SetText(textModel->getText());
    text->SetFont(sf::Font::GetDefaultFont());
    text->SetSize(textSize);
    text->SetX(textModel->getViewStartPosition()->getX());
    text->SetY(textModel->getViewStartPosition()->getY());    

    drawables.push_back(text);
    

}


void TextViewPainter::update() {   
}
    


}
}
