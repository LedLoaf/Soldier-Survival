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
        DEAD_ENEMY_A,
        ENEMY_B,
        DEAD_ENEMY_B,
        ENEMY_C,
        DEAD_ENEMY_C,
        ENEMY_D,
        DEAD_ENEMY_D,
        ENEMY_E,
        DEAD_ENEMY_E,
        BOSS,
        TRADER,
        PLAYER,
        BOMB
    };    
    
    MapObject(Type type);
    
    static bool isEnemy(MapObject* mapObject); 
    static bool isTerrain(MapObject* mapObject); 
    static bool isWall(MapObject* mapObject);  
    static bool isBridge(MapObject* mapObject);  
    static bool isRiver(MapObject* mapObject);  
    
    static Type getDyingMapObjectFor(Type type);
    
    virtual Type getType();
    
protected:
    Type type;

};

} 
#endif 
