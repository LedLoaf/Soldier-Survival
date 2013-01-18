#ifndef GROUND_HPP_
#define GROUND_HPP_

#include <game/object/MapObject.hpp>


namespace game {
    
class Ground : public MapObject {
public:
    Ground(MapObject::Type type);
};
    
}

#endif