/*
 * SelectionViewModel.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef SELECTIONVIEWMODEL_HPP_
#define SELECTIONVIEWMODEL_HPP_

#include <util/Util.hpp>
#include <vector>
#include <iostream>

#include <game/object/weapon/Weapon.hpp>
#include <view/View.hpp>

namespace view {

class SelectionViewModel : public ViewModel {
public:
	class SelectableElement;
    
   enum Type {
        SIMPLE_MENU, SIMPLE_PAUSE_MENU, WEAPONS
    };
    
	SelectionViewModel(Type modelType);
	virtual ~SelectionViewModel();

    void setViewOrientation(view::View::Orientation orientation);
    view::View::Orientation getViewOrientation();
    
    std::vector<SelectableElement*> getSelectableElements();
    
	void setSelected(int positionOfElement);
	void setUnselected(int positionOfElement);

    void addElement(SelectableElement* element);
    
    Type getType();

	class SelectableElement {
	public:
        SelectableElement();
        
        SelectableElement(util::Util::Action action);
        
        virtual void setAction(util::Util::Action action);
		virtual util::Util::Action getAction();
		void setUnselected();
		void setSelected();
        bool isSelected();

        util::Location::Position getPosition();
        
	private:
		bool selected;
        util::Util::Action action;
	};
    
	class WeaponSelectableElement : public SelectableElement {
	public:
        WeaponSelectableElement(game::Weapon* weapon);
        ~WeaponSelectableElement();
        
        util::Location::Position getPosition();
        game::Weapon* getWeapon();
        
	private:
		bool selected;
        util::Util::Action action;
        game::Weapon* weapon;
	};    



private:
	std::vector<SelectableElement*> selectableElements;
    Type type;
    view::View::Orientation orientation;
};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
