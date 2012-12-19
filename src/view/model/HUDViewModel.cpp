/*
 * SelectionViewModel.cpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#include <view/model/HUDViewModel.hpp>

namespace view {

HUDViewModel::HUDViewModel() {
	// TODO Auto-generated constructor stub

}

HUDViewModel::~HUDViewModel() {
	// TODO Auto-generated destructor stub
}

void HUDViewModel::setPlayer(game::Player* player) {
    this->player = player;
    
    
}

int HUDViewModel::getPlayerHealth() {
    return player->getHealth();
}

} /* namespace view */
