#include <view/View.hpp>
#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>

#include <util/Location.hpp>

namespace view {

MapView::MapView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
}


void MapView::moveCharacter(game::Character& ch, util::Location::Vector vector) {
	util::Location::Position position = mapViewModel->getPositionOf(ch);

	mapViewModel->remove(position, ch);

	// tutaj sobie przeladujemy '+' w position, zeby zwrocil nam nowa pozycje przesunieta o dany wektor w stosunku
	// do starej
//	mapModel.put(ch, position + vector);
    
    
}


bool canMoveCharacter(util::Location::Vector vector) {
	// MapView gra role MapHandlera
	// sprawdzam w tablicy z mapa czy jest taka mozliwosc
    // czy nie wyjde poza mape
    // czy na miejscu nie ma przeszkody lub innego charactera
}



View::Type MapView::getType() {
    return View::MAP_VIEW;
}

}
