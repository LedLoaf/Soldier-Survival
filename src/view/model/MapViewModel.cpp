#include <view/model/MapViewModel.hpp>

#include "util/Location.hpp"
#include "game/object/Player.hpp"
#include "game/object/MapObject.hpp"
#include "game/object/NotMovingMapObject.hpp"

namespace view {

MapViewModel::MapViewModel(int mapWidth, int mapHeight) {
    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
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

game::Character* MapViewModel::getCharacter(util::Location::Position position) {
    return getCharacter(position.getX(), position.getY());
}

game::Player* MapViewModel::getPlayer() {
    return dynamic_cast<game::Player*>(charactersTab[playerPositionX][playerPositionY]);
}

game::MapObject* MapViewModel::getNotMovingObject(int x, int y) {
    return notMovingObjectsTab[x][y];
}

game::MapObject* MapViewModel::getNotMovingObject(util::Location::Position position) {
    return getNotMovingObject(position.getX(), position.getY());
}


void MapViewModel::put(int x, int y, game::Character* const ch) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    charactersTab[x][y] = ch;
    
    ch->setPosition(util::Location::Position(x, y));
    
}

void MapViewModel::put(int x, int y, game::Player* const player) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    charactersTab[x][y] = player;
    
    player->setPosition(util::Location::Position(x, y));
    
    playerPositionX = x;
    playerPositionY = y;
}

void MapViewModel::put(int x, int y, game::NotMovingMapObject* const notMovingMapObject ) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    notMovingObjectsTab[x][y] = notMovingMapObject;
}

void MapViewModel::remove(int x, int y, const game::Character* ch) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    charactersTab[x, y] = NULL;
}

void MapViewModel::remove(int x, int y, const game::NotMovingMapObject* notMovingMapObject) {
    //checkIfMapHasPoint(x, y);  throws exception if x > mapWidth ...

    notMovingObjectsTab[x, y] = NULL;
}

util::Location::Position MapViewModel::getPositionOf(game::Character* ch) {
    return ch->getPosition();
}


int MapViewModel::getMapHeight() {
    return mapWidth;
}

int MapViewModel::getMapWidth() {
    return mapHeight;
}

} /* namespace view */
