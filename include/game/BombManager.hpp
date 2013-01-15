#ifndef BOMB_MANAGER_HPP_
#define BOMB_MANAGER_HPP_

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <vector>

#include <util/Location.hpp>

#include <game/object/weapon/Bomb.hpp>

namespace view {
class MapView;  
class WarView;
}

namespace game {

class War;
class Player;
class Enemy;

class BombManager {
public:
    BombManager(view::MapView* mapView);
    
    void plantBomb(util::Location::Position* position, game::Bomb* bomb);
    bool checkIfBombHasBeenPlanted();
    void explodeBomb();
    
private:
    view::MapView* mapView;
    Bomb* plantedBomb;
    util::Location::Position* bombPosition;

};

}

#endif














