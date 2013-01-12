#include <view/model/WarViewModel.hpp>

#include "view/WarView.hpp"
#include "game/object/Character.hpp"
#include <game/object/Enemy.hpp>


namespace view {
    
void WarViewModel::setPlayer(game::Player* player) {
    this->player = player;
}

void WarViewModel::setEnemy(game::Enemy* enemy) {
    this->enemy = enemy;
}
    
int WarViewModel::getEnemyHealth() {
    return enemy->getHealth();
}

util::Location::Position WarViewModel::getEnemyPosition() {
    return enemy->getPosition();
}


} /* namespace view */
