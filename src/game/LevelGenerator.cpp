#include <game/LevelGenerator.hpp>
#include <game/object/LevelDescription.hpp>

#include "view/model/HUDViewModel.hpp"

namespace game {

LevelGenerator::LevelGenerator(game::LevelDescription* levelDescription) {
    this->levelDescription = levelDescription;
}

view::HUDViewModel* LevelGenerator::getHUDViewModel() {
    view::HUDViewModel* hudModel = new view::HUDViewModel();
    
    hudModel->setWeapons(levelDescription->getPlayerWeapons());
}

view::HUDViewModel* LevelGenerator::getMapViewModel() {
    

}
    

}