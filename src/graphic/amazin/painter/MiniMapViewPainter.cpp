#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <util/Location.hpp>
#include <util/Util.hpp>

#include <algorithm>
#include <vector>
#include <map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/String.hpp>

#include <graphic/amazin/painter/MiniMapViewPainter.hpp>

#include "util/Resource.hpp"


namespace graphic {
namespace amazin {

MiniMapViewPainter::MiniMapViewPainter(view::MiniMapViewModel* model) {
	this->miniMapViewModel = model;

	init();
}


void MiniMapViewPainter::init() {
    numberOfColumns = miniMapViewModel->getNumberOfColumns();
    numberOfRows = miniMapViewModel->getNumberOfRows();
    
    viewWidth = miniMapViewModel->getViewEndPosition()->getX() - miniMapViewModel->getViewStartPosition()->getX();
    elementWidth = viewWidth / numberOfColumns;
    
    // TODO: dynamicznie alokowac pamiec dla dwuwymiarowej tablicy map
    sf::Sprite* msap[numberOfColumnsp][numberOfRows];
    
    for (int i = 0; i < numberOfColumns; i++) {
        for (int j = 0; j < numberOfRows; j++) {
            map[i][j] = new sf::Sprite();
            map[i][j]->SetPosition(miniMapViewModel->getViewStartPosition()->getX() + elementWidth * i, elementWidth * j + 1);
        }    
    }
 
}

virtual void MiniMapViewPainter::update() {
    for (int i = 0; i < numberOfColumns; i++) {
        for (int j = 0; j < numberOfRows; j++) {            
            map[i][j]->SetImage(util::SFMLResource::getImage(miniMapViewModel->getTopElementAt(i, j)));
        }    
    }    
}


std::vector<sf::Drawable*> HUDViewPainter::getDrawables() {
    int size = healthIndicatorSprites.size();
    drawables.insert(drawables.end(), healthIndicatorSprites.begin(), healthIndicatorSprites.end());

    
	return drawables;
}

}
}