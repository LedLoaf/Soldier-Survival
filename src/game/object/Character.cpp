#include <game/object/Character.hpp>
#include <game/logic/EnemyLife.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/MapObject.hpp>
#include <game/object/weapon/Weapon.hpp>

namespace game {
    
Character::Character(MapObject::Type type, view::MapViewModel* mapViewModel) : MapObject(type), mapViewModel(mapViewModel),
        position(util::Location::Position(-1, -1)) {
}

view::MapViewModel* Character::getMapModel() {
    return mapViewModel;
}

view::MapView* Character::getMapView() {
    return mapView;
}
    
    // virtualna, tak zeby w Player nie rozpoczynac watku
void Character::beginLife() {
    mapView = mapViewModel->getMapView();
    life->Launch();
}   

void Character::endLife() {
    life->die();
}

void Character::setPosition(util::Location::Position pos) {
    position = pos;
}

util::Location::Position Character::getPosition() {
    return position;
}

void Character::setHealth(int health) {
    this->health = health;
}
int Character::getHealth() {
    return health;
}


void Character::injureUsing(Weapon* weapon) {
   
}


}