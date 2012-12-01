/*
 * SelectionViewModel.cpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#include "SelectionViewModel.hpp"

namespace view {

SelectionViewModel::SelectionViewModel() {
	// TODO Auto-generated constructor stub

}

SelectionViewModel::~SelectionViewModel() {
	// TODO Auto-generated destructor stub
}

void SelectionViewModel::setUnselected(int positionOfElement) {
	selectableElements[positionOfElement].setUnselected();
}

void SelectionViewModel::setSelected(int positionOfElement) {
	selectableElements[positionOfElement].setSelected();

}

int SelectionViewModel::getSize()() {
	return selectableElements.size();
}


void SelectionViewModel::SelectableElement::setSelected() {
	isSelected = true;
}

void SelectionViewModel::SelectableElement::setUnselected() {
	isSelected = false;
}


} /* namespace view */
