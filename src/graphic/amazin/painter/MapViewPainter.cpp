#include <cstddef> //do poprawnej kompilacji SFML //(NULL)

#include <graphic/amazin/painter/MapViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "view/model/ImageViewModel.hpp"
#include "util/Resource.hpp"
#include "util/SFMLAmazinResource.hpp"
#include "util/Key.hpp"
#include "game/object/Character.hpp"
#include <game/object/Player.hpp>

#include <string>
#include <iostream>

namespace graphic {
namespace amazin {


MapViewPainter::MapViewPainter(view::MapViewModel* model) {
    this->mapViewModel = model;
    
    init();
}
    
void MapViewPainter::allocateMapElementSprites(int subMapWidth, int subMapHeight) {
    mapElementSprites = new sf::Sprite**[subMapWidth];
    for (int i = 0; i < subMapWidth; i++)
        mapElementSprites[i] = new sf::Sprite*[subMapHeight];    
}

void MapViewPainter::init() {
    subMapWidth = 50;
    subMapHeight = 50;
    int playerToWallSpace = 5;
    
    elementSize = 10;
    
    subMapManager = new SubMapManager(mapViewModel, subMapWidth, subMapHeight, playerToWallSpace);
    // rysuje 50 na 50 kafelkow
    subMapManager->setSubMapWidth(subMapWidth);
    subMapManager->setSubMapHeight(subMapHeight);
    
    allocateMapElementSprites(subMapWidth, subMapHeight);
    
    
    for (int i = 0; i < subMapWidth; i++) {
        for (int j = 0; j < subMapHeight; j++) {
            sf::Sprite* element = new sf::Sprite();
            element->SetPosition(i * elementSize, j * elementSize);
            mapElementSprites[i][j] = element;
            drawables.push_back(mapElementSprites[i][j]);
        }        
    }    
}


void MapViewPainter::update() {   
    for (int i = 0; i < subMapWidth; i++) {
        for (int j = 0; j < subMapHeight; j++) {
            std::cout << "MapViewPainter::update() mapElementSprites[ " << i << " ]" << "[ " << j << " ]" << std::endl;
            mapElementSprites[i][j]->SetImage(*(util::SFMLAmazinResource::getInstance()->getImage(subMapManager->getElementAt(i, j)->getType())));
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
    
    util::Location::Position playerPos = model->getPlayer()->getPosition();
    leftWallPos = playerPos.getX() - playerToWallSpace;
    if (leftWallPos <= 0)
        leftWallPos = model->getPositionOf(player).getX();
    
    topWallPos = playerPos.getY() - playerToWallSpace;
    if (leftWallPos < 0)
        leftWallPos = playerPos.getX();    
}

void MapViewPainter::SubMapManager::setSubMapWidth(int width) {
    subMapWidth = width;
}

void MapViewPainter::SubMapManager::setSubMapHeight(int height) {
    subMapHeight = height;
}

void MapViewPainter::SubMapManager::updateSubMap() {
    int playerPosX = mapViewModel->getPositionOf(player).getX();
    
    if (playerPosX - leftWallPos == playerToWallSpace) {
        SmoothlyMoveSubmapThread* smoothlyMoveSubmapThread = new SmoothlyMoveSubmapThread(&leftWallPos, util::Key::LEFT);
        smoothlyMoveSubmapThread->Launch();
        
    } else if (playerPosX - leftWallPos == playerToWallSpace) {
        SmoothlyMoveSubmapThread* smoothlyMoveSubmapThread = new SmoothlyMoveSubmapThread(&leftWallPos, util::Key::RIGHT);
        smoothlyMoveSubmapThread->Launch();
        
    }
}


game::MapObject* MapViewPainter::SubMapManager::getElementAt(int x, int y) {   
    std::cout << "mapViewModel->getVisibleMapObject(" << this->leftWallPos + x << ", " << this->topWallPos + y << ")" << std::endl;
    std::cout << "MapObjectType: " << util::Util::getNameOfMapObjectType(
            mapViewModel->getVisibleMapObject(leftWallPos + x, topWallPos + y)->getType()) << std::endl;
    
    return mapViewModel->getVisibleMapObject(leftWallPos + x, topWallPos + y);   
}

}
}