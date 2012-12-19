/*
 * SelectionViewModel.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef HUD_VIEW_MODEL_HPP
#define HUD_VIEW_MODEL_HPP

#include <util/Util.hpp>
#include <vector>
#include <iostream>

#include <view/View.hpp>

namespace view {

class HUDViewModel : public ViewModel {
public:
	class SelectableElement;

	HUDViewModel();
	virtual ~HUDViewModel();

    game::Weapon* getPlayerWeapon(int pos);
    std::vector<game::Weapon*> getPlayerWeapons();
    
    void setPlayer(game::Player* player);
    
    int getPlayerHealth();
    
    void setPlayerEquipment(game::Equipment* equipment);
    game::Equipment* getPlayerEquipment();
private:
    game::Player* player;
};

} /* namespace view */
#endif
