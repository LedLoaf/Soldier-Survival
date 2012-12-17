#ifndef LEVEL_GENERATOR_H_
#define LEVEL_GENERATOR_H_

#include <object/LevelDescription.hpp>



namespace game {

class LevelGenerator {
public:
    LevelGenerator(game::LevelDescription* levelDescription);
    view::HUDViewModel* getHUDViewModel();
    view::MapViewModel* getMapViewModel();
    
    
private:
    game::LevelDescription* levelDescription;
    
    void generateWalls();
    void generateForest();
    void generateRivers();
    void placeEnemies();
    void placeBoss();
    void placeNPC();
    void placePlayer();
    void placeRandomly(Point *p, int dx, int dy, float density, tileType tt);
    bool checkClearAround(Point *p, int radius);
    bool placeRiverOrBridge(Point *p, int bridgeProbability);
};

}

#endif

