#ifndef MAP_VIEW_HPP_
#define MAP_VIEW_HPP_


#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/Character.hpp>
#include <util/Location.hpp>

namespace view {

class MapView : public View {
private:
	// MapViewModel jest doslownie modelem - nie ma zadnej konkretnej logiki, trzyma tylko 2 tablice 2 wymiarowe z mapa
	MapViewModel* mapViewModel;
    game::WarManager* warManager;

public:
    MapView(int xStart, int yStart, int xEnd, int yEnd);
    virtual Type getType();

    bool areColliding(game::Character* firstCharacter, game::Character* secondCharacter);
    
    void moveCharacter(game::Character* ch, util::Location::Vector vector);

    bool canMoveCharacter(game::Character* ch, util::Location::Vector vector); 
    bool isPositionInMapArea(util::Location::Position position);
    bool canCharacterStayOnNMMO(game::MapObject* notMovingMapObject);
    
    void setMapModel(MapViewModel* mapModel);
    void setWarManager(game::WarManager* warManager);
    
    game::Player* getPlayer();
};

}

#endif
