#ifndef LEVEL_GENERATOR_DESCRIPTION_H_
#define LEVEL_GENERATOR_DESCRIPTION_H_

#include <object/LevelDescription.hpp>



namespace game {

class LevelGenerator {
public:
    LevelGenerator(game::LevelDescription* levelDescription);
    view::HUDViewModel* getHUDViewModel();
    view::HUDViewModel* getMapViewModel();
    
    
private:
    game::LevelDescription* levelDescription;
};

}

#endif

