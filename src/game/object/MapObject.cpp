#include <iostream>

#include <game/object/MapObject.hpp>


namespace game {
    
MapObject::MapObject(Type type) {
    this->type = type;
}
    
bool MapObject::isTerrain(MapObject* mapObject) {
    if (mapObject->getType() == MapObject::GRASS || MapObject::SAND || MapObject::GROUND || MapObject::ROAD || MapObject::BRIDGE) 
        return true;
    else
        return false;
}

bool MapObject::isWall(MapObject* mapObject) {
    if (mapObject->getType() == MapObject::WALL) 
        return true;
    else
        return false;
}

bool MapObject::isBridge(MapObject* mapObject) {
    if (mapObject->getType() == MapObject::BRIDGE) 
        return true;
    else
        return false;
}

bool MapObject::isRiver(MapObject* mapObject) {
    if (mapObject->getType() == MapObject::RIVER) 
        return true;
    else
        return false;
}

MapObject::Type MapObject::getType() {
    return type;
}

}