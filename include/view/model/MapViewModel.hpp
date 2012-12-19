#ifndef MAP_VIEW_MODEL_HPP_
#define MAP_VIEW_MODEL_HPP_

#include <game/object/Character.hpp>
#include <util/Util.hpp>
#include <vector>
#include <iostream>

namespace view {

class MapViewModel : ViewModel {
public:
    MapViewModel(int mapWidth, int mapHeight);
    int getMapHeight();
    int getMapWidth();
    
    
	void remove(int x, int y, const game::Character* ch);
	void remove(int x, int y, const game::NotMovingMapObject* notMovingMapObject);

	util::Location::Position getPositionOf(const game::Character* ch);
    game::MapObject* getVisibleMapObjectAt(int x, int y); 
    
	void put(int x, int y, const game::Character* ch);
	void put(int x, int y, const game::Player* player);
	void put(int x, int y, const game::NotMovingMapObject* notMovingMapObject);
    
    game::MapObject* getNotMovingObject(int x, int y);
    game::Character* getCharacter(int x, int y);
    
    bool hasCharacter(int x, int y);
    
    game::Player* getPlayer();
    
private:
    game::Character** charactersTab;
    game::NotMovingMapObject** notMovingObjectsTab;
    
    int playerPositionX;
    int playerPositionY;
    
    
};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
