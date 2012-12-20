#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/Character.hpp>
#include <util/Location.hpp>

namespace view {

class MapView : public View {
private:
	// MapViewModel jest doslownie modelem - nie ma zadnej konkretnej logiki, trzyma tylko 2 tablice 2 wymiarowe z mapa
	MapViewModel* mapViewModel;

public:
    MapView(int xStart, int yStart, int xEnd, int yEnd);
    virtual Type getType();

    void moveCharacter(game::Character* ch, util::Location::Vector vector);
    bool canMoveCharacter(game::Character* ch, util::Location::Vector vector); 
    bool isPositionInMapArea(util::Location::Position position);
    bool canCharacterStayOnNMMO(game::MapObject* notMovingMapObject);
    void setMapModel(MapViewModel* mapModel);
    
    game::Player* getPlayer();
};

}
