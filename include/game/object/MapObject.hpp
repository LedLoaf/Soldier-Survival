#ifndef MAP_OBJECT_HPP_
#define MAP_OBJECT_HPP_


namespace game {

class MapObject {
public:
    enum Type {
        GRASS,
        GRASS_GREEN,
        SAND,
        GROUND,
        WALL,
        RIVER,
        BRIDGE,
        ROAD,
        TREE,
        ENEMY_A,
        ENEMY_B,
        BOSS,
        TRADER,
        PLAYER
    };    
    
    MapObject(Type type);
    
    static bool isTerrain(MapObject* mapObject); 
    static bool isWall(MapObject* mapObject);  
    static bool isBridge(MapObject* mapObject);  
    static bool isRiver(MapObject* mapObject);  
    
    virtual Type getType();
    
protected:
    Type type;

};

} 
#endif 
