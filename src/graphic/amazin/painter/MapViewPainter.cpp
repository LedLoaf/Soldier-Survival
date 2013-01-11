#include <cstddef> //do poprawnej kompilacji SFML //(NULL)

#include <graphic/amazin/painter/MapViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "view/model/ImageViewModel.hpp"
#include "util/Resource.hpp"
#include "util/SFMLAmazinResource.hpp"
#include "util/Key.hpp"
#include <util/Location.hpp>
#include "game/object/Character.hpp"
#include <game/object/Player.hpp>

#include <string>
#include <iostream>

namespace graphic {
namespace amazin {
    
bool MapViewPainter::SubMapManager::mapIsUpdating;    
int MapViewPainter::SubMapManager::leftWallPos;  
int MapViewPainter::SubMapManager::topWallPos;  
int MapViewPainter::SubMapManager::subMapWidth;  
int MapViewPainter::SubMapManager::subMapHeight;  


MapViewPainter::MapViewPainter(view::MapViewModel* model) {
    this->mapViewModel = model;
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
    
    elementWidth = mapViewWidth / subMapWidth;
    elementHeight = mapViewHeight / subMapHeight;
    
    subMapManager = new SubMapManager(mapViewModel, subMapWidth, subMapHeight, playerToWallSpace);

    
    allocateMapElementSprites(subMapWidth, subMapHeight);
}
    
void MapViewPainter::allocateMapElementSprites(int subMapWidth, int subMapHeight) {
    mapElementSprites = new sf::Sprite**[subMapWidth];
    for (int i = 0; i < subMapWidth; i++) {
        mapElementSprites[i] = new sf::Sprite*[subMapHeight];
        
        for (int j = 0; j < subMapHeight; j++) {
            sf::Sprite* element = new sf::Sprite();
            element->SetPosition(mapViewModel->getViewStartPosition()->getX() + i * elementWidth, 
                    mapViewModel->getViewStartPosition()->getY() + j * elementHeight);
            
            mapElementSprites[i][j] = element;
            drawables.push_back(mapElementSprites[i][j]);
        }            
        
    }
}

void MapViewPainter::update() {   
    sf::Image* elementImage;
    for (int i = 0; i < subMapWidth; i++) {
        for (int j = 0; j < subMapHeight; j++) {
            game::MapObject::Type elementType = subMapManager->getElementAt(i, j)->getType();
            elementImage = sfmlAmazinResource->getImage(elementType);

            mapElementSprites[i][j]->SetImage(*(elementImage));
            mapElementSprites[i][j]->Resize(elementWidth, elementHeight);
            

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
    if (!mapIsUpdating) {
        int playerPosX = mapViewModel->getPositionOf(player).getX();
        int playerPosY = mapViewModel->getPositionOf(player).getY();

        int distanceToRightWall = leftWallPos + subMapWidth - playerPosX;
        int distanceToBottomWall = topWallPos + subMapWidth - playerPosY;

        std::cout << "leftWallPos: " << leftWallPos << ", playerPosX: " << playerPosX << std::endl;

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
}


game::MapObject* MapViewPainter::SubMapManager::getElementAt(int x, int y) {   
//    std::cout << "mapViewModel->getVisibleMapObject(" << this->leftWallPos + x << ", " << this->topWallPos + y << ")" << std::endl;
//    std::cout << "MapObjectType: " << util::Util::getNameOfMapObjectType(
//            mapViewModel->getVisibleMapObject(leftWallPos + x, topWallPos + y)->getType()) << std::endl;
    
    return mapViewModel->getVisibleMapObject(leftWallPos + x, topWallPos + y);   
}

}
}