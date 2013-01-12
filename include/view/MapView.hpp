#ifndef MAP_VIEW_HPP_
#define MAP_VIEW_HPP_


#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>

#include <util/Location.hpp>

#include <game/WarManager.hpp>
#include "WarView.hpp"


namespace game {
class MapObject;    
class Character;
class Player;
}

namespace view {
    
class WarView;
    
class MapView : public View {
private:
	// MapViewModel jest doslownie modelem - nie ma zadnej konkretnej logiki, trzyma tylko 2 tablice 2 wymiarowe z mapa
	MapViewModel* mapViewModel;
    game::WarManager* warManager;

public:
    MapView(int xStart, int yStart, int xEnd, int yEnd);
    virtual Type getType();
    MapViewModel* getModel();

    static int getDistanceBetween(game::Character* firstCharacter, game::Character* secondCharacter);
    
    bool areColliding(game::Character* firstCharacter, game::Character* secondCharacter);
    
    void moveCharacter(game::Character* ch, util::Location::Vector vector);
    void moveCharacter(game::Player* player, util::Location::Vector vector);

    bool canMoveCharacter(game::Character* ch, util::Location::Vector vector); 
    bool isPositionInMapArea(util::Location::Position position);
    bool canCharacterStayOnNMMO(game::MapObject* notMovingMapObject);
    
    void setModel(MapViewModel* mapModel);
    void setWarManager(game::WarManager* warManager);
    
    void startWar(game::War* war);
    

    
    game::Player* getPlayer();
};

}

#endif
