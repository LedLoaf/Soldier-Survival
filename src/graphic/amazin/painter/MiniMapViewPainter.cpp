#include <cstddef> //do poprawnej kompilacji SFML //(NULL)

#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <util/Location.hpp>
#include <util/Util.hpp>
#include <util/SFMLAmazinResource.hpp>

#include <algorithm>
#include <vector>
#include <map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/String.hpp>

#include <graphic/amazin/painter/MiniMapViewPainter.hpp>


namespace graphic {
namespace amazin {

MiniMapViewPainter::MiniMapViewPainter(view::MiniMapViewModel* model) {
	this->miniMapViewModel = model;
    this->mapViewModel = miniMapViewModel->getMapViewModel();
    this->sfmlAmazinResource = util::SFMLAmazinResource::getInstance();
	init();
}

void MiniMapViewPainter::init() {
    int miniMapViewWidth = miniMapViewModel->getViewEndPosition()->getX() - miniMapViewModel->getViewStartPosition()->getX();
    int miniMapViewHeight = miniMapViewModel->getViewEndPosition()->getY() - miniMapViewModel->getViewStartPosition()->getY();    
    
    numberOfRows = mapViewModel->getMapWidth();
    numberOfColumns = mapViewModel->getMapHeight();
    
    
    elementWidth = miniMapViewWidth / numberOfRows;
    elementHeight = miniMapViewHeight / numberOfColumns;
    
    std::cout << "MiniMapViewPainter::init(): " << "elementWidth: " << elementWidth << "elementHeight: " << elementHeight << std::endl;
    
    allocateMapElementSprites(numberOfRows, numberOfColumns);
}
    
void MiniMapViewPainter::allocateMapElementSprites(int mapViewRowsNo, int mapViewColumnsNo) {
    mapElementSprites = new sf::Sprite**[mapViewRowsNo];
    for (int i = 0; i < mapViewRowsNo; i++) {
        mapElementSprites[i] = new sf::Sprite*[mapViewColumnsNo];
        
        for (int j = 0; j < mapViewColumnsNo; j++) {
            sf::Sprite* element = new sf::Sprite();
            element->SetPosition(miniMapViewModel->getViewStartPosition()->getX() + i * elementWidth, 
                    miniMapViewModel->getViewStartPosition()->getY() + j * elementHeight);
            
            mapElementSprites[i][j] = element;
            drawables.push_back(mapElementSprites[i][j]);
        }            
        
    }
}

void MiniMapViewPainter::update() {   
    sf::Image* elementImage;
    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            game::MapObject::Type elementType = mapViewModel->getVisibleMapObject(i, j)->getType();
            
            elementImage = sfmlAmazinResource->getImage(elementType);

            mapElementSprites[i][j]->SetImage(*(elementImage));
            mapElementSprites[i][j]->Resize(elementWidth, elementHeight);
            

        }        
    }
}


}
}