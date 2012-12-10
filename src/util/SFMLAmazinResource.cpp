#include <util/SFMLAmazinResource.hpp>
#include <string>

#include "view/model/MapViewModel.hpp"

namespace util {

SFMLAmazinResource* SFMLAmazinResource::getInstance() {
	if (!SFMLAmazinResource::instance) {
		SFMLAmazinResource::instance = new SFMLAmazinResource();
        instance->init();
	}

	return SFMLAmazinResource::instance;
}    
    
sf::Image* SFMLAmazinResource::getImage(view::MapViewModel::Element element) {
    return imageResourceMap.find(element)->second;
}

void SFMLAmazinResource::init() {
    std::string grassYellowPath = "resource/graphic/amazin/game_play/img/grass_yellow.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(grassYellowPath)) {
        std::cout << "Failed to load " << grassYellowPath << std::endl;
    }    
    
    imageResourceMap.insert(std::pair<view::MapViewModel::Element, sf::Image*>(
        view::MapViewModel::YELLOW_GRASS, image));

    
    
    std::string grassGreenPath = "resource/graphic/amazin/game_play/img/grass_green.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(grassGreenPath)) {
        std::cout << "Failed to load " << grassYellowPath << std::endl;
    }    
    
    imageResourceMap.insert(std::pair<view::MapViewModel::Element, sf::Image*>(
        view::MapViewModel::GREEN_GRASS, image));    
    
    
}



}
