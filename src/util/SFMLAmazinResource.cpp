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

	std::string healthPackAPath = "resource/graphic/amazin/game_play/img/tiles/first_aid.png";
    
    sf::Image* healthPackAImage = new sf::Image();
    if (!healthPackAImage->LoadFromFile(healthPackAPath))
        std::cout << "Failed to load " << healthPackAPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::HEALTH_PACK, healthPackAImage));     
    
    
	std::string foodPath = "resource/graphic/amazin/game_play/img/tiles/first_aid.png";
    
    sf::Image* foodImage = new sf::Image();
    if (!foodImage->LoadFromFile(healthPackAPath))
        std::cout << "Failed to load " << healthPackAPath << std::endl;
    
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
        game::MapObject::FOOD, foodImage));    
    
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


    std::string enemy1Path = "resource/graphic/amazin/game_play/img/tiles/enemy1.png";
    
    sf::Image* enemy1Image = new sf::Image();
    if (!enemy1Image->LoadFromFile(enemy1Path))
        std::cout << "Failed to load " << enemy1Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_A, enemy1Image)); 

    std::string deadEnemy1Path = "resource/graphic/amazin/game_play/img/tiles/enemy1_dead.png";
    
    sf::Image* deadEnemy1Image = new sf::Image();
    if (!deadEnemy1Image->LoadFromFile(deadEnemy1Path))
        std::cout << "Failed to load " << deadEnemy1Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::DEAD_ENEMY_A, deadEnemy1Image));     

    std::string enemy2Path = "resource/graphic/amazin/game_play/img/tiles/enemy2.png";
    
    sf::Image* enemy2Image = new sf::Image();
    if (!enemy2Image->LoadFromFile(enemy2Path))
        std::cout << "Failed to load " << enemy2Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_B, enemy2Image)); 
    
    std::string deadEnemy2Path = "resource/graphic/amazin/game_play/img/tiles/enemy2_dead.png";
    
    sf::Image* deadEnemy2Image = new sf::Image();
    if (!deadEnemy2Image->LoadFromFile(deadEnemy2Path))
        std::cout << "Failed to load " << deadEnemy2Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::DEAD_ENEMY_B, deadEnemy2Image));   
    
    std::string enemy3Path = "resource/graphic/amazin/game_play/img/tiles/enemy3.png";
    
    sf::Image* enemy3Image = new sf::Image();
    if (!enemy3Image->LoadFromFile(enemy3Path))
        std::cout << "Failed to load " << enemy3Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_C, enemy3Image)); 

    std::string deadEnemy3Path = "resource/graphic/amazin/game_play/img/tiles/enemy3_dead.png";
    
    sf::Image* deadEnemy3Image = new sf::Image();
    if (!deadEnemy3Image->LoadFromFile(deadEnemy3Path))
        std::cout << "Failed to load " << deadEnemy3Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::DEAD_ENEMY_C, deadEnemy3Image));
    
    std::string enemy4Path = "resource/graphic/amazin/game_play/img/tiles/enemy4.png";
    
    sf::Image* enemy4Image = new sf::Image();
    if (!enemy4Image->LoadFromFile(enemy4Path))
        std::cout << "Failed to load " << enemy4Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_D, enemy4Image)); 

    std::string deadEnemy4Path = "resource/graphic/amazin/game_play/img/tiles/enemy4_dead.png";
    
    sf::Image* deadEnemy4Image = new sf::Image();
    if (!deadEnemy4Image->LoadFromFile(deadEnemy4Path))
        std::cout << "Failed to load " << deadEnemy4Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::DEAD_ENEMY_D, deadEnemy4Image));
    
    std::string enemy5Path = "resource/graphic/amazin/game_play/img/tiles/enemy5.png";
    
    sf::Image* enemy5Image = new sf::Image();
    if (!enemy5Image->LoadFromFile(enemy5Path))
        std::cout << "Failed to load " << enemy5Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::ENEMY_E, enemy5Image)); 

    std::string deadEnemy5Path = "resource/graphic/amazin/game_play/img/tiles/enemy5_dead.png";
    
    sf::Image* deadEnemy5Image = new sf::Image();
    if (!deadEnemy5Image->LoadFromFile(deadEnemy5Path))
        std::cout << "Failed to load " << deadEnemy5Path << std::endl;
       
    imageResourceMap.insert(std::pair<game::MapObject::Type, sf::Image*>(
		game::MapObject::DEAD_ENEMY_E, deadEnemy5Image));
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
