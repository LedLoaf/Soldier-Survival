#include <view/SelectionView.hpp>

using namespace view;

void SelectionView::selectNextElement() {
	if (canSelectNextElement()) {
		model.setSelected(++mPositionOfSelectedElement);
	}
}

bool SelectionView::canSelectNextElement() {
	if (mPositionOfSelectedElement < model.getSize())
		return true;

	return false;
}

	
}
