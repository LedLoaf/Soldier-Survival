#ifndef NOT_MOVING_MAP_OBJECT_HPP_
#define NOT_MOVING_MAP_OBJECT_HPP_

#include <game/object/MapObject.hpp>


namespace game {
    
class NotMovingMapObject : public MapObject {
public:
    NotMovingMapObject(MapObject::Type type);
};
    
}

#endif