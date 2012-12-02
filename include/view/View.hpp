/*
 * View.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <view/model/ViewModel.hpp>

namespace view {

class View {
public:
	enum Type {
		SELECTION_VIEW, IMAGE_VIEW, MAP_VIEW, MAIN_MENU_WINDOW
	};
    
    View(int xStart, int yStart, int xEnd, int yEnd);

	virtual ~View();
	virtual Type getType() = 0;

protected:
    int xStart, yStart, xEnd, yEnd;
};

} /* namespace graphic */
#endif /* VIEW_HPP_ */
