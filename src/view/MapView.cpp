#include <view/View.hpp>
#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>

#include <util/Location.hpp>

namespace view {

MapView::MapView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
}


void MapView::moveCharacter(game::Character& ch, util::Location::Vector vector) {
	// getPositionOf() jest generyczna - mozna tam podac np. referencje do danego kafeleku rzeki
//	util::Location::Position position = mapModel.getPositionOf(ch);
//
//	mapModel.remove(position, ch);

	// tutaj sobie przeladujemy '+' w position, zeby zwrocil nam nowa pozycje przesunieta o dany wektor w stosunku
	// do starej
//	mapModel.put(ch, position + vector);
}


bool canMoveCharacter(util::Location::Vector vector) {
	// MapView gra role MapHandlera
	// sprawdzam w tablicy z mapa czy jest taka mozliwosc
}



View::Type MapView::getType() {
    return View::MAP_VIEW;
}

}
