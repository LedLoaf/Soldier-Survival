#include <graphic/amazin/painter/ImageViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "view/model/ImageViewModel.hpp"
#include "util/Resource.hpp"

#include <string>
#include <iostream>

namespace graphic {
namespace amazin {


ImageViewPainter::ImageViewPainter(view::ImageViewModel* model, view::View::Type parentViewType) {
    this->imageViewModel = model;
    
    init();
}
    

void ImageViewPainter::init() {
    std::string imgPath;
    
    switch (imageViewModel->getImageResource()) {
        case util::Resource::MAIN_MENU_LOGO :
            imgPath = "resource/graphic/amazin/main_menu/img/game_logo.jpg";
    }
    
    // wskaznik, bo inaczej zostanie zniszczony
    // w destruktorze niszczyc
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(imgPath)) {
        std::cout << "Failed to load " << imgPath << std::endl;
    }
    
    sf::Sprite* sprite = new sf::Sprite;
    sprite->SetX(imageViewModel->getViewStartPosition()->getX());
    sprite->SetY(imageViewModel->getViewStartPosition()->getY());    
    sprite->SetImage(*image);
    

    
    drawables.push_back(sprite);
}


void ImageViewPainter::update() {   
    
}
    


}
}
