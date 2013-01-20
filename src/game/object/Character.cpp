#include <game/object/Character.hpp>
#include <game/logic/EnemyLife.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/MapObject.hpp>
#include <game/object/weapon/Weapon.hpp>

#include "view/window/GamePlayWindow.hpp"
#include "game/Application.hpp"

namespace game {
    
Character::Character(MapObject::Type type, view::MapViewModel* mapViewModel) : MapObject(type), mapViewModel(mapViewModel),
        position(util::Location::Position(-1, -1)) {
    alive = false;
}

Character::~Character() {
    delete life;
}

view::MapViewModel* Character::getMapModel() {
    return mapViewModel;
}

view::MapView* Character::getMapView() {
    return mapView;
}
    
bool Character::isAlive() {
    return alive;
}
    // virtualna, tak zeby w Player nie rozpoczynac watku
void Character::beginLife() {
    mapView = mapViewModel->getMapView();
    life->Launch();
    alive = true;
}   

void Character::pauseLife() {
    life->pause();
    alive = false;
}

void Character::resumeLife() {
    life->resume();
    alive = true;
}

void Character::endLife() {
    life->die();
    alive = false;
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

void Character::addHealth(int health) {
    this->health += health;
}

int Character::getHealth() {
    return health;
}


void Character::injureUsing(Weapon* weapon) {   
}


}