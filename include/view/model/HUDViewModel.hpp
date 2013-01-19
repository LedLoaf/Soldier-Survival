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
#include <game/object/Player.hpp>

namespace game {
class Weapon;    
}

namespace view {

class HUDViewModel : public ViewModel {
public:
	class SelectableElement;

	HUDViewModel();
	virtual ~HUDViewModel();

    void setCurrentWeaponForPlayer(game::Weapon* weapon);
    game::Weapon* getPlayerWeapon(int pos);
    std::vector<game::Weapon*> getPlayerWeapons();
    
    void setPlayer(game::Player* player);
    
    int getPlayerHealth();
    
    void setPlayerEquipment(game::Equipment* equipment);
    game::Equipment* getPlayerEquipment();
    
private:
    game::Player* player;
    game::Equipment* playerEquipment;
};

} /* namespace view */
#endif
