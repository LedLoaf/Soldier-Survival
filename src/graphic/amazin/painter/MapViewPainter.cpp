#include <cstddef> //do poprawnej kompilacji SFML //(NULL)
#include <iostream>
#include <string>


#include <graphic/amazin/painter/MapViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "view/model/ImageViewModel.hpp"
#include "util/Resource.hpp"
#include "util/SFMLAmazinResource.hpp"
#include "util/Key.hpp"
#include <util/Location.hpp>
#include "game/object/Character.hpp"
#include "view/model/MiniMapViewModel.hpp"
#include <game/object/Player.hpp>

#include <game/object/MapObject.hpp>
#include <game/object/Ground.hpp>
#include <game/object/NotMovingMapObject.hpp>
#include <game/object/Character.hpp>

namespace graphic {
namespace amazin {
    
    
bool MapViewPainter::SubMapManager::mapIsUpdating;    
int MapViewPainter::SubMapManager::leftWallPos;  
int MapViewPainter::SubMapManager::topWallPos;  
int MapViewPainter::SubMapManager::subMapWidth;  
int MapViewPainter::SubMapManager::subMapHeight;  



MapViewPainter::MapViewPainter(view::MapViewModel* mapModel) {
    this->mapViewModel = mapModel;
    this->sfmlAmazinResource = util::SFMLAmazinResource::getInstance();
    init();
}


void MapViewPainter::init() {
    // rysuje 50 na 50 kafelkow

    subMapWidth = 20;
    subMapHeight = 20;
    int mapViewWidth = mapViewModel->getViewEndPosition()->getX() - mapViewModel->getViewStartPosition()->getX();
    int mapViewHeight = mapViewModel->getViewEndPosition()->getY() - mapViewModel->getViewStartPosition()->getY();
    
    int playerToWallSpace = 5;
    
    elementWidth = 40;
    elementHeight = 25;
    
    std::cout << elementWidth << ", " << elementHeight;
    
    subMapManager = new SubMapManager(mapViewModel, subMapWidth, subMapHeight, playerToWallSpace);

    
    allocateAllMapElementSprites(subMapWidth, subMapHeight);
}
    
void MapViewPainter::allocateAllMapElementSprites(int subMapWidth, int subMapHeight) {
    groundSprites = new sf::Sprite**[subMapWidth];
    notMovingMapObjectSprites = new sf::Sprite**[subMapWidth];
    characterSprites = new sf::Sprite**[subMapWidth];
    
    for (int i = 0; i < subMapWidth; i++) {
        groundSprites[i] = new sf::Sprite*[subMapHeight];
        notMovingMapObjectSprites[i] = new sf::Sprite*[subMapHeight];
        characterSprites[i] = new sf::Sprite*[subMapHeight];
        
        for (int j = 0; j < subMapHeight; j++) {
            sf::Sprite* groundSprite = new sf::Sprite();
            groundSprite->SetPosition(mapViewModel->getViewStartPosition()->getX() + i * elementWidth, 
                    mapViewModel->getViewStartPosition()->getY() + j * elementHeight);
            groundSprites[i][j] = groundSprite;
            drawables.push_back(groundSprites[i][j]);
            
            sf::Sprite* notMovingMapObjectSprite = new sf::Sprite();
            notMovingMapObjectSprite->SetPosition(mapViewModel->getViewStartPosition()->getX() + i * elementWidth, 
                    mapViewModel->getViewStartPosition()->getY() + j * elementHeight);
            notMovingMapObjectSprites[i][j] = notMovingMapObjectSprite;
            drawables.push_back(notMovingMapObjectSprites[i][j]);  
            
            sf::Sprite* characterSprite = new sf::Sprite();
            characterSprite->SetPosition(mapViewModel->getViewStartPosition()->getX() + i * elementWidth, 
                    mapViewModel->getViewStartPosition()->getY() + j * elementHeight);
            characterSprites[i][j] = characterSprite;
            drawables.push_back(characterSprites[i][j]);              
        }            
        
    }
}

void MapViewPainter::update() {   
    sf::Image* elementImage;
    for (int i = 0; i < subMapWidth; i++) {
        for (int j = 0; j < subMapHeight; j++) {
            game::MapObject::Type elementType;
            
            elementType = subMapManager->getGroundMapObjectAt(i, j)->getType();
            elementImage = sfmlAmazinResource->getImage(elementType);

            groundSprites[i][j]->SetImage(*(elementImage));
            groundSprites[i][j]->Resize(elementWidth, elementHeight);
            
            if (subMapManager->getNotMovingMapObjectAt(i, j) != NULL) {
                elementType = subMapManager->getNotMovingMapObjectAt(i, j)->getType();
                elementImage = sfmlAmazinResource->getImage(elementType);

                notMovingMapObjectSprites[i][j]->SetImage(*(elementImage));
                notMovingMapObjectSprites[i][j]->Resize(elementWidth, elementHeight);
            } else
                notMovingMapObjectSprites[i][j]->Resize(1, 1);  

            
            if (subMapManager->getCharacterAt(i, j) != NULL) {
                elementType = subMapManager->getCharacterAt(i, j)->getType();
                elementImage = sfmlAmazinResource->getImage(elementType);
                
                characterSprites[i][j]->SetImage(*(elementImage));
                characterSprites[i][j]->Resize(elementWidth, elementHeight);                     
            } else
                characterSprites[i][j]->Resize(1, 1);                     
        }        
    }
    
    
    subMapManager->updateSubMap();
}
    

MapViewPainter::SubMapManager::SubMapManager(view::MapViewModel* model, int subMapWidth, int subMapHeight, int playerToWallSpace) {
    this->subMapWidth = subMapWidth;
    this->subMapHeight = subMapHeight;
    this->playerToWallSpace = playerToWallSpace;
    this->player = model->getPlayer();
    this->mapViewModel = model;
    this->mapIsUpdating = false;
    
    util::Location::Position playerPos = model->getPlayer()->getPosition();
    
    
    if (playerPos.getX() >= subMapWidth/2) {
        leftWallPos = playerPos.getX() - subMapWidth/2;
    } else {
        leftWallPos = 0;
    }
    
    if (playerPos.getY() >= subMapHeight/2) {
        topWallPos = playerPos.getY() - subMapHeight/2;
    }
    else {
        topWallPos = 0;
    }
    
//    std::cout << "SubMapManager::SubMapManager(), leftWallPos: " << leftWallPos << ", topWallPos" << topWallPos << std::endl;
}

void MapViewPainter::SubMapManager::setSubMapWidth(int width) {
    subMapWidth = width;
}

void MapViewPainter::SubMapManager::setSubMapHeight(int height) {
    subMapHeight = height;
}

void MapViewPainter::SubMapManager::updateSubMap() {
    int playerPosX = mapViewModel->getPositionOf(player).getX();
    int playerPosY = mapViewModel->getPositionOf(player).getY();

    int distanceToRightWall = leftWallPos + subMapWidth - playerPosX;
    int distanceToBottomWall = topWallPos + subMapWidth - playerPosY;

//    std::cout << "leftWallPos: " << leftWallPos << ", playerPosX: " << playerPosX << std::endl;

    // przesun pionowa sciane submapy w lewo
    if (playerPosX - leftWallPos < playerToWallSpace && leftWallPos > 0) {
            SmoothlyMoveSubmapWallThread* smoothlyMoveSubmapThread = new SmoothlyMoveSubmapWallThread(mapViewModel, 
                    &leftWallPos, playerToWallSpace, util::Key::LEFT);
            smoothlyMoveSubmapThread->Launch();

    } //  przesun pionowa sciane submapy w prawo
    else if (distanceToRightWall < playerToWallSpace && leftWallPos + subMapWidth < mapViewModel->getMapWidth()) {
            SmoothlyMoveSubmapWallThread* smoothlyMoveSubmapThread = new SmoothlyMoveSubmapWallThread(mapViewModel, 
                    &leftWallPos, playerToWallSpace, util::Key::RIGHT);
            smoothlyMoveSubmapThread->Launch();
    }
    else if (playerPosY - topWallPos < playerToWallSpace && topWallPos > 0) {
            SmoothlyMoveSubmapWallThread* smoothlyMoveSubmapThread = new SmoothlyMoveSubmapWallThread(mapViewModel, 
                    &topWallPos, playerToWallSpace, util::Key::UP);
            smoothlyMoveSubmapThread->Launch();
    } 
    else if (distanceToBottomWall < playerToWallSpace && topWallPos + subMapHeight < mapViewModel->getMapHeight()) {
        SmoothlyMoveSubmapWallThread* smoothlyMoveSubmapThread = new SmoothlyMoveSubmapWallThread(mapViewModel, 
                &topWallPos, playerToWallSpace, util::Key::DOWN);
        smoothlyMoveSubmapThread->Launch();

    }      
}


game::MapObject* MapViewPainter::SubMapManager::getGroundMapObjectAt(int x, int y) {
    return mapViewModel->getGround(leftWallPos + x, topWallPos + y);
}

game::MapObject* MapViewPainter::SubMapManager::getNotMovingMapObjectAt(int x, int y) {
    return mapViewModel->getNotMovingObject(leftWallPos + x, topWallPos + y);
}

game::MapObject* MapViewPainter::SubMapManager::getCharacterAt(int x, int y) {
    return mapViewModel->getCharacter(leftWallPos + x, topWallPos + y);
}


}

}