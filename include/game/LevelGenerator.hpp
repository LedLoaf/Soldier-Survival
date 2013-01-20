#ifndef LEVEL_GENERATOR_H_
#define LEVEL_GENERATOR_H_

#include <game/object/LevelDescription.hpp>

#include "object/Player.hpp"
#include "object/MapObject.hpp"
#include <view/model/HUDViewModel.hpp>
#include <view/model/MapViewModel.hpp>



namespace game {

class LevelGenerator {
public:
    LevelGenerator(game::LevelDescription* levelDescription);
    view::HUDViewModel* getHUDViewModel();
    view::MapViewModel* getMapViewModel();
    
    
private:
    game::LevelDescription* levelDescription;
    view::MapViewModel* mapModel;
    Player* player;
    
    void generateWalls();
    void generateForest();
    void generateRivers();
    void generatePaths();
    void generateGrass();
    void generateSand();
    void generateGround();
    void generatePlayer();
    void placeEnemies();
    void placeBoss();
//    void placeNPC();
    void placePlayer();
    void placeRandomly(util::Location::Position *p, int dx, int dy, float density, MapObject* tt);
    bool checkClearAround(util::Location::Position *p, int radius);
    bool placeRiverOrBridge(util::Location::Position *p, int bridgeProbability);
    bool placePath(util::Location::Position *p);
    void placeHealthPacks();
};

}

#endif

