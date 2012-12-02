
#ifndef MAP_VIEW_MODEL_HPP_
#define MAP_VIEW_MODEL_HPP_

#include <game/object/Character.hpp>
#include <util/Util.hpp>
#include <vector>
#include <iostream>

namespace view {

class MapViewModel : ViewModel {
public:
	void remove(util::Location::Position position, const game::Character& ch);
//	void remove(util::Location::Position position, const game::Terrain& terrain);


	util::Location::Position getPositionOf(const game::Character& ch);

	void put(util::Location::Position position, const game::Character& ch);
//	void put(util::Location::Position position, const game::object::Terrain& terrain);

};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
