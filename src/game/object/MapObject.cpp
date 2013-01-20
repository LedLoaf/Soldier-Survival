#include <iostream>

#include <game/object/MapObject.hpp>


namespace game {
    
MapObject::MapObject(Type type) {
    this->type = type;
}

bool MapObject::isEnemy(MapObject* mapObject) {
    switch (mapObject->getType()) {
        case MapObject::ENEMY_A:
        case MapObject::ENEMY_B:
        case MapObject::ENEMY_C:
        case MapObject::ENEMY_D:
        case MapObject::ENEMY_E:
            return true;
        default:
            return false;
    }
}


bool MapObject::isTerrain(MapObject* mapObject) {
    if (mapObject->getType() == MapObject::GRASS || mapObject->getType() == MapObject::SAND || 
            mapObject->getType() == MapObject::GROUND || mapObject->getType() == MapObject::ROAD || mapObject->getType() == MapObject::BRIDGE) 
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

MapObject::Type MapObject::getDyingMapObjectFor(Type type) {
    switch (type) {
        case ENEMY_A:
            return DEAD_ENEMY_A;
        default:
            return DEAD_ENEMY_A;
    }
}

}