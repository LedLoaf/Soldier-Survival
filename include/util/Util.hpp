#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <sstream>
#include <string>

#include <game/object/MapObject.hpp>

namespace util {
    
class Util {
public:
    enum Action {
        RUN_LEVEL_SELECTION, RUN_ABOUT, RUN_EXIT, RUN_GAME_PLAY,
        RESUME_GAME, RETURN_TO_MAIN_MENU
    };  
    
    std::string static toString(int integer) {
        std::ostringstream os;
        os << integer;

        return os.str();
    }
    
    int static getCurrentTime();
    
    std::string static getNameOfMapObjectType(game::MapObject::Type mapObjectType) {
        switch (mapObjectType) {
            case game::MapObject::BOSS:
                return std::string("Boss");
            case game::MapObject::BRIDGE:
                return std::string("Bridge");
            case game::MapObject::ENEMY_A:
                return std::string("Enemy_A");
            case game::MapObject::ENEMY_B:
                return std::string("Enemy_B");
            case game::MapObject::GRASS:
                return std::string("Grass");
            case game::MapObject::GRASS_GREEN:
                return std::string("Grass Green");
            case game::MapObject::GROUND:
                return std::string("Ground");
            case game::MapObject::PLAYER:
                return std::string("Player");
            case game::MapObject::RIVER:
                return std::string("River");  
            case game::MapObject::ROAD:
                return std::string("Road");
            case game::MapObject::SAND:
                return std::string("Sand");
            case game::MapObject::TRADER:
                return std::string("Trader");  
            case game::MapObject::TREE:
                return std::string("Tree");
            case game::MapObject::WALL:
                return std::string("Wall");      
            default:
                return std::string("---Name not found--- util::Util::getNameOfMapObjectType()");
        }
        
    }
 
};

}
 /* namespace util */
#endif /* DEVICEMANAGER_HPP_ */
