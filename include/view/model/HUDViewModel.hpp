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

    game::Weapon* getWeapon(int pos);
    std::vector<game::Weapon*> getWeapons();
    
    void setWeapons(std::vector<game::Weapon*> weapons);

private:

};

} /* namespace view */
#endif
