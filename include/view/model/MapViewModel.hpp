
#ifndef MAP_VIEW_MODEL_HPP_
#define MAP_VIEW_MODEL_HPP_

#include <util/Action.hpp>
#include <vector>
#include <iostream>

namespace view {

class MapViewModel : ViewModel {
public:
	void remove(util::Location::Position position, const game::object::Character& ch);
	void remove(util::Location::Position position, const game::object::Terrain& terrain);


	util::Location::Position getPositionOf(const game::object::Character& ch);

	void put(util::Location::Position position, const game::object::Character& ch);
	void put(util::Location::Position position, const game::object::Terrain& terrain);




private:
	std::vector<SelectableElement&> selectableElements;

};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
