#ifndef SELECTION_VIEW_HPP_
#define SELECTION_VIEW_HPP_

#include <view/View.hpp>
#include <iostream>
#include <list>


namespace view {

class SelectionView : View {
public:
	void selectNextElement();
	bool hasNextElement();
	SelectionViewModel::SelectableElement& getSelectedElement();

private:
	SelectionViewModel model;
	int positionOfSelectedElement;
	
};

}
#endif
