#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/object/Character.hpp>
#include <util/Location.hpp>

namespace view {

class MapView : View {
private:
	// MapViewModel jest doslownie modelem - nie ma zadnej konkretnej logiki, trzyma tylko 2 tablice 2 wymiarowe z mapa
	MapViewModel& mapModel;

public:

	void generateLevel(game::LevelDescription& levelDescription);
	void moveCharacter(game::Character& ch, util::Location::Vector vector);
	bool canMoveCharacter(util::Location::Vector vector);
	void generateMapModel(game::LevelDescription& levelDescription);
	
};

}
