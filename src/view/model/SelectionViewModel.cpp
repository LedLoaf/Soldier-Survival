/*
 * SelectionViewModel.cpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#include <view/model/SelectionViewModel.hpp>

namespace view {

SelectionViewModel::SelectionViewModel() {
	// TODO Auto-generated constructor stub

}

SelectionViewModel::~SelectionViewModel() {
	// TODO Auto-generated destructor stub
}

void SelectionViewModel::setUnselected(int positionOfElement) {
	selectableElements.at(positionOfElement)->setUnselected();
}

void SelectionViewModel::setSelected(int positionOfElement) {
	selectableElements.at(positionOfElement)->setSelected();

}

int SelectionViewModel::getSize() {
	return selectableElements.size();
}


void SelectionViewModel::SelectableElement::setSelected() {
	selected = true;
}

void SelectionViewModel::SelectableElement::setUnselected() {
	selected = false;
}

void SelectionViewModel::SelectableElement::setAction(Util::Action action) {
	this->action = action;
}

Util::Action SelectionViewModel::SelectableElement::getAction() {
	return action;
}

std::vector<SelectionViewModel::SelectableElement*> SelectionViewModel::getSelectableElements() {
    return selectableElements;
}


void SelectionViewModel::SelectableElement::setElementHeight(int height) {
    elementHeight = height;
}

void SelectionViewModel::SelectableElement::setElementWidth(int width) {
    elementWidth = width;
}

int SelectionViewModel::SelectableElement::getElementHeight() {
    return elementHeight;
}

int SelectionViewModel::SelectableElement::getElementWidth() {
    return elementWidth;
}

void SelectionViewModel::addElement(SelectableElement* element) {
    SelectableElement* lastElement = *selectableElements.back();

    // vertical view
    element->setPosition(new util::Location::Position(getViewPosition().getX(), 
            lastElement->getPosition().getY() + lastElement->getElementHeight()));

    selectableElements.push_back(element);
}

} /* namespace view */
