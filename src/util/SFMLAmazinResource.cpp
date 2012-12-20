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
    // TODO: scaling of images
    return imageResourceMap.find(mapObjectType)->second;
}

void SFMLAmazinResource::init() {
//    std::string grassYellowPath = "resource/graphic/amazin/game_play/img/grass_yellow.jpg";
//    
//    sf::Image* image = new sf::Image();
//    if (!image->LoadFromFile(grassYellowPath)) {
//        std::cout << "Failed to load " << grassYellowPath << std::endl;
//    }    
//    
//    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
//        game::MapObject::YELLOW_GRASS, image));

    
/* NotMovingMapObjects */   
    
    std::string grassGreenPath = "resource/graphic/amazin/game_play/img/grass_green.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(grassGreenPath))
        std::cout << "Failed to load " << grassGreenPath << std::endl;
    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GRASS_GREEN, image)); 
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GRASS, image));     
    
    
    std::string wallPath = "resource/graphic/amazin/game_play/img/grass_green.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(wallPath))
        std::cout << "Failed to load " << wallPath << std::endl;
    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::WALL, image));     
    
    
   std::string riverPath = "resource/graphic/amazin/game_play/img/grass_green.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(riverPath))
        std::cout << "Failed to load " << riverPath << std::endl;
    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::RIVER, image));      
    
    
   std::string bridgePath = "resource/graphic/amazin/game_play/img/grass_green.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(bridgePath))
        std::cout << "Failed to load " << bridgePath << std::endl;
    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::BRIDGE, image));          
    
    
/* Characters */
    
    std::string playerPath = "resource/graphic/amazin/game_play/img/character/player.jpg";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(playerPath))
        std::cout << "Failed to load " << playerPath << std::endl;
    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::PLAYER, image));     
    
    
}



}
