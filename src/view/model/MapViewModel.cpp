#include <view/model/MapViewModel.hpp>

#include "util/Location.hpp"
#include "game/object/Player.hpp"
#include "game/object/MapObject.hpp"
#include "game/object/NotMovingMapObject.hpp"

namespace view {

MapViewModel::MapViewModel() {
	// TODO Auto-generated constructor stub

}

game::MapObject* MapViewModel::getVisibleMapObject(int x, int y) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...
    
    if (hasMapCharacterAt(x, y)) 
        return getCharacter(x, y);
    else 
        return getNotMovingObject(x, y);
}

bool MapViewModel::hasMapCharacterAt(int x, int y) {
    if (charactersTab[x][y] == NULL)
        return false;
    return true;
}

game::Character* MapViewModel::getCharacter(int x, int y) {
    return charactersTab[x][y];
}

void MapViewModel::put(int x, int y, const game::Character* ch) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    charactersTab[x, y] = ch;
}

void MapViewModel::put(int x, int y, const game::Player* player) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    charactersTab[x, y] = player;
    
    playerPositionX = x;
    playerPositionY = y;
}

void MapViewModel::put(int x, int y, const game::NotMovingMapObject* notMovingMapObject) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    notMovingObjectsTab[x, y] = notMovingMapObject;
}

void MapViewModel::remove(int x, int y, const game::Character* ch) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    charactersTab[x, y] = NULL;
}

void MapViewModel::remove(int x, int y, const game::NotMovingMapObject* notMovingMapObject) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    notMovingObjectsTab[x, y] = NULL;
}

} /* namespace view */
