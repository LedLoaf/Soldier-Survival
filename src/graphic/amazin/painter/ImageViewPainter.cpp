#include <graphic/amazin/painter/ImageViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "view/model/ImageViewModel.hpp"

namespace graphic {
namespace amazin {


ImageViewPainter::ImageViewPainter(view::ImageViewModel* model, view::View::Type parentViewType) {
    this->imageViewModel = model;
}
    

void ImageViewPainter::init() {
    sf::Image image;
    if (!image.LoadFromFile(imageViewModel->getImagePath())) {
        //TODO: throw exception
    }
    
    sf::Sprite* sprite = new sf::Sprite;
    sprite->SetImage(image);

    
    sprites.push_back(sprite);
}


void ImageViewPainter::update() {   
}
    


}
}
