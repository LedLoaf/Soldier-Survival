#include <view/View.hpp>


namespace view {

class MapView : View {
private:
	// MapViewModel jest doslownie modelem - nie ma zadnej konkretnej logiki, trzyma tylko 2 tablice 2 wymiarowe z mapa
	MapViewModel& mapModel;

public:

	MapView(LevelDescription& levelDescription);

	void moveCharacter(Character& ch, vector);
	bool canMoveCharacter(vector);
	void generateMapModel(LevelDescription& levelDescription);
	
};

}
