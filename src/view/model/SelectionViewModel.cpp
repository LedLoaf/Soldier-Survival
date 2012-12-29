/*
 * SelectionViewModel.cpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#include <view/model/SelectionViewModel.hpp>

#include "game/object/weapon/Weapon.hpp"

namespace view {

SelectionViewModel::SelectionViewModel(Type modelType) {
	this->type = modelType;
}

SelectionViewModel::~SelectionViewModel() {
	// TODO Auto-generated destructor stub
}

void SelectionViewModel::setViewOrientation(view::View::Orientation orientation) {
    this->orientation = orientation;
}

view::View::Orientation SelectionViewModel::getViewOrientation() {
    return this->orientation;
}

void SelectionViewModel::setUnselected(int positionOfElement) {
	selectableElements.at(positionOfElement)->setUnselected();
}

void SelectionViewModel::setSelected(int positionOfElement) {
	selectableElements.at(positionOfElement)->setSelected();

}

void SelectionViewModel::SelectableElement::setSelected() {
	selected = true;
}

void SelectionViewModel::SelectableElement::setUnselected() {
	selected = false;
}

bool SelectionViewModel::SelectableElement::isSelected() {
    return selected;
}

void SelectionViewModel::SelectableElement::setAction(util::Util::Action action) {
	this->action = action;
}

SelectionViewModel::SelectableElement::SelectableElement() {
}

SelectionViewModel::SelectableElement::SelectableElement(util::Util::Action action) {
    this->action = action;
    this->selected = false;
}

util::Util::Action SelectionViewModel::SelectableElement::getAction() {
	return action;
}

SelectionViewModel::WeaponSelectableElement::WeaponSelectableElement(game::Weapon* weapon) : SelectionViewModel::SelectableElement() {
    this->weapon = weapon;
}

game::Weapon* SelectionViewModel::WeaponSelectableElement::getWeapon() {
	return weapon;
}

std::vector<SelectionViewModel::SelectableElement*> SelectionViewModel::getSelectableElements() {
    return selectableElements;
}

void SelectionViewModel::addElement(SelectableElement* element) {
    selectableElements.push_back(element);
}

SelectionViewModel::Type SelectionViewModel::getType() {
    return type;
}


} /* namespace view */
