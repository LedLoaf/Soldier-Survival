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
    
    
	void remove(util::Location::Position position, const game::Character& ch);
//	void remove(util::Location::Position position, const game::Terrain& terrain);


	util::Location::Position getPositionOf(const game::Character* ch);

    game::MapObject* getVisibleMapObjectAt(int x, int y); 
    
    // Wojtek, zamien sobie na int x, int y zamiast util::Location::Position jak Ci wygodniej
	void put(util::Location::Position position, const game::Character& ch);
	void put(util::Location::Position position, const game::Player& player); // pozycje playera trzymamy w osobnych zmiennych zeby miec szybki dostep
	void put(util::Location::Position position, const game::Terrain& terrain);
	void put(util::Location::Position position, const game::Obstacle& obstacle);
    
    game::MapObject* get(int x, int y);

    game::Player* getPlayer();
    
};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
