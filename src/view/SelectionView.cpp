#include <view/SelectionView.hpp>
#include <util/Location.hpp>

namespace view {

SelectionView::SelectionView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
    selectionModel = new SelectionViewModel();
    selectionModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
}    
    
void SelectionView::selectNextElement() {
	selectionModel->setUnselected(positionOfSelectedElement);
	selectionModel->setSelected(++positionOfSelectedElement);
}

bool SelectionView::hasNextElement() {
	if (positionOfSelectedElement < selectionModel->getSelectableElements().size())
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