#include <view/SelectionView.hpp>

namespace view {

SelectionView::SelectionView() {
    selectionModel =  new SelectionViewModel();
}    
    
void SelectionView::selectNextElement() {
	selectionModel->setUnselected(positionOfSelectedElement);
	selectionModel->setSelected(++positionOfSelectedElement);
}

bool SelectionView::hasNextElement() {
	if (positionOfSelectedElement < selectionModel->getSize())
		return true;
	else
		return false;
}

void SelectionView::setSelectionModel(SelectionViewModel* selectionViewModel) { 
    this->selectionModel = selectionViewModel;
}

SelectionViewModel* SelectionView::getModel() {
    return this->selectionModel;
}


View::Type SelectionView::getType() {
    return view::View::SELECTION_VIEW;
}

SelectionViewModel::SelectableElement* SelectionView::getSelectedElement() {
    return getModel()->getSelectableElements().at(positionOfSelectedElement);
}

void SelectionView::addElement(SelectionViewModel::SelectableElement* element) {
    selectionModel->addElement(element);
}


}