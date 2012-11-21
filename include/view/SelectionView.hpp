#ifndef SELECTION_VIEW_HPP_
#define SELECTION_VIEW_HPP_

#include <view/View.hpp>

namespace view {

class SelectionView : View {
private:
	SelectionViewModel model;

public:
	void selectNextElement();
	bool canSelectNextElement();
	
};

}
#endif
