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
    
    std::string grassGreenPath = "resource/graphic/amazin/game_play/img/tiles/grass.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(grassGreenPath))
        std::cout << "Failed to load " << grassGreenPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GRASS_GREEN, image)); 
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GRASS, image));     
    
    
    std::string wallPath = "resource/graphic/amazin/game_play/img/tiles/wall.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(wallPath))
        std::cout << "Failed to load " << wallPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::WALL, image));     
    
    
   std::string riverPath = "resource/graphic/amazin/game_play/img/tiles/river.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(riverPath))
        std::cout << "Failed to load " << riverPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::RIVER, image));      
    
    
   std::string bridgePath = "resource/graphic/amazin/game_play/img/tiles/bridge.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(bridgePath))
        std::cout << "Failed to load " << bridgePath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::BRIDGE, image));          
    

	std::string roadPath = "resource/graphic/amazin/game_play/img/tiles/path.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(roadPath))
        std::cout << "Failed to load " << roadPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ROAD, image));


	std::string treePath = "resource/graphic/amazin/game_play/img/tiles/tree.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(treePath))
        std::cout << "Failed to load " << treePath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::TREE, image));  

	
	std::string groundPath = "resource/graphic/amazin/game_play/img/tiles/ground.png"; 
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(groundPath))
        std::cout << "Failed to load " << groundPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::GROUND, image));

	
	std::string sandPath = "resource/graphic/amazin/game_play/img/tiles/sand.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(sandPath))
        std::cout << "Failed to load " << sandPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::SAND, image));


/* Characters */
    
    std::string playerPath = "resource/graphic/amazin/game_play/img/tiles/soldier.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(playerPath))
        std::cout << "Failed to load " << playerPath << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::PLAYER, image));     
    
    
	std::string traderPath = "resource/graphic/amazin/game_play/img/tiles/trader.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(traderPath))
        std::cout << "Failed to load " << traderPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::TRADER, image)); 


	std::string bossPath = "resource/graphic/amazin/game_play/img/tiles/boss.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(bossPath))
        std::cout << "Failed to load " << bossPath << std::endl;
      
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::BOSS, image)); 


    std::string enemy1Path = "resource/graphic/amazin/game_play/img/tiles/enemy2.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(enemy1Path))
        std::cout << "Failed to load " << enemy1Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_A, image)); 


    std::string enemy2Path = "resource/graphic/amazin/game_play/img/tiles/enemy3.png";
    
    sf::Image* image = new sf::Image();
    if (!image->LoadFromFile(enemy2Path))
        std::cout << "Failed to load " << enemy2Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_B, image)); 
}



}
