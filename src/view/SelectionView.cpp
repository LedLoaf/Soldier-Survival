#include <view/model/ViewModel.hpp>
#include <view/SelectionView.hpp>
#include <util/Location.hpp>

namespace view {

SelectionView::SelectionView(int xStart, int yStart, int xEnd, int yEnd, SelectionViewModel::Type modelType) : View(xStart, yStart, xEnd, yEnd) {
    selectionModel = new SelectionViewModel(modelType);
    selectionModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
    
    positionOfSelectedElement = 0;
    selectionModel->setViewOrientation(view::View::VERTICAL);
}    

void SelectionView::setOrientation(view::View::Orientation orientation) {
    this->selectionModel->setViewOrientation(orientation);
}
    
void SelectionView::selectPreviousElement() {
	selectionModel->setUnselected(positionOfSelectedElement);
	selectionModel->setSelected(--positionOfSelectedElement);
}

bool SelectionView::hasPreviousElement() {
	if (positionOfSelectedElement - 1 >= 0)
		return true;
	else
		return false;
}

void SelectionView::selectNextElement() {
	selectionModel->setUnselected(positionOfSelectedElement);
	selectionModel->setSelected(++positionOfSelectedElement);
}

bool SelectionView::hasNextElement() {
    int size = selectionModel->getSelectableElements().size();
    
	if (positionOfSelectedElement < selectionModel->getSelectableElements().size() - 1)
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

void SelectionView::selectElement(int pos) {
//    TODO: rzucac wyjatek jezeli pos > liczba elementow
    if (pos < selectionModel->getSelectableElements().size()) 
        selectionModel->setSelected(pos);
}

view::ViewModel* SelectionView::getViewModel() {
    return selectionModel;
}

}