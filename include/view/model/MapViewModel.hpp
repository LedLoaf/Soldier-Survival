#ifndef MAP_VIEW_MODEL_HPP_
#define MAP_VIEW_MODEL_HPP_


#include <util/Util.hpp>
#include <vector>
#include <iostream>

#include <view/model/ViewModel.hpp>
#include <game/object/NotMovingMapObject.hpp>

namespace game {
    class Character;
    class Player;
}


namespace view {

class MapViewModel : public ViewModel {
public:
    MapViewModel(int mapWidth, int mapHeight);
    int getMapHeight();
    int getMapWidth();
    
    
	void remove(int x, int y, const game::Character* ch);
	void remove(int x, int y, const game::NotMovingMapObject* notMovingMapObject);

	util::Location::Position getPositionOf(game::Character* ch);
    game::MapObject* getVisibleMapObject(int x, int y); 
    game::MapObject* getVisibleMapObject(util::Location::Position position); 
    
    
	void put(int x, int y, game::Character* const ch);
	void put(int x, int y, game::Player* const player);
	void put(int x, int y, game::NotMovingMapObject* const notMovingMapObject);
    
    game::MapObject* getNotMovingObject(int x, int y);
    game::MapObject* getNotMovingObject(util::Location::Position position);
    
    game::Character* getCharacter(int x, int y);
    game::Character* getCharacter(util::Location::Position position);
    
    bool hasMapCharacterAt(int x, int y);
    
    game::Player* getPlayer();
    
private:
    game::Character*** charactersTab;
    game::NotMovingMapObject*** notMovingObjectsTab;
    
    int playerPositionX;
    int playerPositionY;
    
    int mapWidth, mapHeight;
    
    void allocateCharactersTab();
    void allocateNotMovingObjectsTab();
    
    
};

} /* namespace view */
#endif 
