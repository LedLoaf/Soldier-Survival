#include <view/SelectionView.hpp>

using namespace view;

void SelectionView::selectNextElement() {
	model.setUnselected(positionOfSelectedElement);
	model.setSelected(++positionOfSelectedElement);
}

bool SelectionView::hasNextElement() {
	if (positionOfSelectedElement < model.getSize())
		return true;
	else
		return false;
}

	
}
