#include <util/SFMLAmazinResource.hpp>
#include <string>
#include <iostream>

#include "view/model/MapViewModel.hpp"
#include "game/object/MapObject.hpp"
#include "game/object/Equipment.hpp"



namespace util {

SFMLAmazinResource* SFMLAmazinResource::instance;


SFMLAmazinResource::SFMLAmazinResource() {
}  

SFMLAmazinResource* SFMLAmazinResource::getInstance() {
	if (!SFMLAmazinResource::instance) {
		SFMLAmazinResource::instance = new SFMLAmazinResource();
        instance->init();
	}

	return SFMLAmazinResource::instance;
}    
    
sf::Image* SFMLAmazinResource::getImage(game::MapObject::Type mapObjectType) {
//    std::cout << "SFMLAmazinResource::getImage()" << std::endl;
    
    std::map<game::MapObject::Type, sf::Image*>::iterator imageResourceMapIterator;
    imageResourceMapIterator = imageResourceMap.find(mapObjectType);
    
    
    if (imageResourceMapIterator != imageResourceMap.end())
        return imageResourceMapIterator->second;
    else
        return imageNotFound;
}

sf::Image* SFMLAmazinResource::getTransparentImage() {
    return transparentImage;
}


void SFMLAmazinResource::init() {
    initEquipmentItemImages();
    initMapObjectImages();
    initSpecialImages();
}


void SFMLAmazinResource::initMapObjectImages() {
    std::string imageNotFoundPath = "resource/graphic/amazin/game_play/img/tiles/image_not_found.jpg";
    
    imageNotFound = new sf::Image();
    if (!imageNotFound->LoadFromFile(imageNotFoundPath))
        std::cout << "Failed to load " << imageNotFoundPath << std::endl;    
    
    
/* NotMovingMapObjects */   
    
	std::string bombAPath = "resource/graphic/amazin/game_play/img/weapon/bomb.png";
    
    sf::Image* bombAImage = new sf::Image();
    if (!bombAImage->LoadFromFile(bombAPath))
        std::cout << "Failed to load " << bombAPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::BOMB, bombAImage)); 

    
    std::string grassGreenPath = "resource/graphic/amazin/game_play/img/tiles/grass.png";
    
    sf::Image* grassImage = new sf::Image();
    if (!grassImage->LoadFromFile(grassGreenPath))
        std::cout << "Failed to load " << grassGreenPath << std::endl;
    
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GRASS_GREEN, grassImage)); 
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::GRASS, grassImage));     
    
    
    std::string wallPath = "resource/graphic/amazin/game_play/img/tiles/wall.png";
    
    sf::Image* wallImage = new sf::Image();
    if (!wallImage->LoadFromFile(wallPath))
        std::cout << "Failed to load " << wallPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::WALL, wallImage));     
    
    
   std::string riverPath = "resource/graphic/amazin/game_play/img/tiles/river.png";
    
    sf::Image* riverImage = new sf::Image();
    if (!riverImage->LoadFromFile(riverPath))
        std::cout << "Failed to load " << riverPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::RIVER, riverImage));      
    
    
   std::string bridgePath = "resource/graphic/amazin/game_play/img/tiles/bridge.png";
    
    sf::Image* bridgeImage = new sf::Image();
    if (!bridgeImage->LoadFromFile(bridgePath))
        std::cout << "Failed to load " << bridgePath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::BRIDGE, bridgeImage));          
    

	std::string roadPath = "resource/graphic/amazin/game_play/img/tiles/path.png";
    
    sf::Image* roadImage = new sf::Image();
    if (!roadImage->LoadFromFile(roadPath))
        std::cout << "Failed to load " << roadPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ROAD, roadImage));


	std::string treePath = "resource/graphic/amazin/game_play/img/tiles/tree.png";
    
    sf::Image* treeImage = new sf::Image();
    if (!treeImage->LoadFromFile(treePath))
        std::cout << "Failed to load " << treePath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::TREE, treeImage));  

	
	std::string groundPath = "resource/graphic/amazin/game_play/img/tiles/ground.png"; 
    
    sf::Image* groundImage = new sf::Image();
    if (!groundImage->LoadFromFile(groundPath))
        std::cout << "Failed to load " << groundPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::GROUND, groundImage));

	
	std::string sandPath = "resource/graphic/amazin/game_play/img/tiles/sand.png";
    
    sf::Image* sandImage = new sf::Image();
    if (!sandImage->LoadFromFile(sandPath))
        std::cout << "Failed to load " << sandPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::SAND, sandImage));

    
  

/* Characters */
    
    std::string playerPath = "resource/graphic/amazin/game_play/img/tiles/soldier.png";
    
    sf::Image* playerImage = new sf::Image();
    if (!playerImage->LoadFromFile(playerPath))
        std::cout << "Failed to load " << playerPath << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::PLAYER, playerImage));     
    
    
	std::string traderPath = "resource/graphic/amazin/game_play/img/tiles/trader.png";
    
    sf::Image* traderImage = new sf::Image();
    if (!traderImage->LoadFromFile(traderPath))
        std::cout << "Failed to load " << traderPath << std::endl;
        
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::TRADER, traderImage)); 


	std::string bossPath = "resource/graphic/amazin/game_play/img/tiles/boss.png";
    
    sf::Image* bossImage = new sf::Image();
    if (!bossImage->LoadFromFile(bossPath))
        std::cout << "Failed to load " << bossPath << std::endl;
      
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::BOSS, bossImage)); 


    std::string enemy1Path = "resource/graphic/amazin/game_play/img/tiles/enemy2.png";
    
    sf::Image* enemyAImage = new sf::Image();
    if (!enemyAImage->LoadFromFile(enemy1Path))
        std::cout << "Failed to load " << enemy1Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_A, enemyAImage)); 

    std::string deadEnemyAPath = "resource/graphic/amazin/game_play/img/tiles/enemy2_dead.png";
    
    sf::Image* deadEnemyImage = new sf::Image();
    if (!deadEnemyImage->LoadFromFile(deadEnemyAPath))
        std::cout << "Failed to load " << deadEnemyAPath << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::DEAD_ENEMY_A, deadEnemyImage));     

    std::string enemy2Path = "resource/graphic/amazin/game_play/img/tiles/enemy3.png";
    
    sf::Image* enemyBImage = new sf::Image();
    if (!enemyBImage->LoadFromFile(enemy2Path))
        std::cout << "Failed to load " << enemy2Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_B, enemyBImage)); 
}

sf::Image* SFMLAmazinResource::getRedDot() {
    return redDot;
}

void SFMLAmazinResource::initEquipmentItemImages() {     
}

void SFMLAmazinResource::initSpecialImages() {
    std::string transparentImagePath = "resource/graphic/amazin/game_play/img/tiles/transparent.png";
    
    transparentImage = new sf::Image();
    if (!transparentImage->LoadFromFile(transparentImagePath))
        std::cout << "Failed to load " << transparentImagePath << std::endl;   
    
    std::string redDotPath = "resource/graphic/amazin/game_play/img/tiles/red_dot.png";
    
    redDot = new sf::Image();
    if (!redDot->LoadFromFile(redDotPath))
        std::cout << "Failed to load " << redDotPath << std::endl;   
    
}
}
