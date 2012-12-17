#include <graphic/amazin/painter/MapViewPainter.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "view/model/ImageViewModel.hpp"
#include "util/Resource.hpp"
#include "util/SFMLAmazinResource.hpp"
#include "util/Key.hpp"

#include <string>
#include <iostream>

namespace graphic {
namespace amazin {


MapViewPainter::MapViewPainter(view::MapViewModel* model, view::View::Type parentViewType) {
    this->mapViewModel = model;
    
    init();
}
    

void MapViewPainter::init() {
    subMapWidth = 50;
    subMapHeight = 50;
    
    elementSize = 10;
    
    SubMapManager* subMapManager = SubMapManager(mapViewModel, subMapWidth, subMapHeight);
    // rysuje 50 na 50 kafelkow
    subMapManager->setSubMapWidth(subMapWidth);
    subMapManager->setSubMapHeight(subMapHeight);
    
    
    for (int i = 0; i < subMapWidth; i++) {
        for (int j = 0; i < subMapHeight; j++) {
            sf::Sprite* element = new sf::Sprite();
            element->SetPosition(i * elementSize, j * elementSize);
            mapElementSprites[i][j] = element;
        }        
    }    
}


void MapViewPainter::update() {   
    for (int i = 0; i < subMapWidth; i++) {
        for (int j = 0; i < subMapHeight; j++) {
            mapElementSprites[i][j].setImage(util::SFMLAmazinResource::getInstance()->getImage(subMapManager->getElementAt(i, j)));
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
    
    util::Location::Position playerPos = model->getPositionOf(player);
    leftWallPos = playerPos.getX() - playerToWallSpace;
    if (leftWallPos <= 0)
        leftWallPos = model->getPositionOf(player).getX();
    
    topWallPos = playerPos.getY() - playerToWallSpace;
    if (leftWallPos < 0)
        leftWallPos = playerPos.getX();    
}

MapViewPainter::SubMapManager::updateSubMap() {
    int playerPosX = mapViewModel->getPositionOf(player).getX();
    
    if (playerPosX - leftWallPos == playerToWallSpace) {
        SmoothlyMoveSubmapThread smoothlyMoveSubmapThread = new SmoothlyMoveSubmapThread(&leftWallPos, util::Key::LEFT);
        smoothlyMoveSubmapThread->Launch();
        
    } else if (playerPosX - leftWallPos == playerToWallSpace) {
        SmoothlyMoveSubmapThread smoothlyMoveSubmapThread = new SmoothlyMoveSubmapThread(&leftWallPos, util::Key::RIGHT);
        smoothlyMoveSubmapThread->Launch();
        
    }
}


MapViewPainter::SubMapManager::getElementAt(int x, int y) {   
    return mapViewModel->getVisibleMapObjectAt()[leftWallPos + x][topWallPos + y];   
}
