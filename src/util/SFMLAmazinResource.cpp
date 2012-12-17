#include <util/SFMLAmazinResource.hpp>
#include <string>

#include "view/model/MapViewModel.hpp"
#include "game/object/MapObject.hpp"

namespace util {

SFMLAmazinResource* SFMLAmazinResource::getInstance() {
	if (!SFMLAmazinResource::instance) {
		SFMLAmazinResource::instance = new SFMLAmazinResource();
        instance->init();
	}

	return SFMLAmazinResource::instance;
}    
    
sf::Image* SFMLAmazinResource::getImage(game::MapObject::Type mapObjectType) {
    return imageResourceMap.find(mapObjectType)->second;
}

void SFMLAmazinResource::init() {
    std::string grassYellowPath = "resource/graphic/amazin/game_play/img/grass_yellow.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(grassYellowPath)) {
        std::cout << "Failed to load " << grassYellowPath << std::endl;
    }    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::YELLOW_GRASS, image));

    
    
    std::string grassGreenPath = "resource/graphic/amazin/game_play/img/grass_green.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(grassGreenPath)) {
        std::cout << "Failed to load " << grassYellowPath << std::endl;
    }    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GREEN_GRASS, image));    
    
    
}



}