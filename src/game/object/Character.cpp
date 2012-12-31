#include <game/object/Character.hpp>
#include <game/logic/EnemyLife.hpp>

namespace game {
    
Character::Character(MapObject::Type type) : MapObject(type), position(util::Location::Position(-1, -1)) {
}
    
    // virtualna, tak zeby w Player nie rozpoczynac watku
void Character::beginLife() {
    life->Launch();
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