/*
 * View.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <vector>
#include <view/model/ViewModel.hpp>

namespace view {

class View {
public:
	enum Type {
		SELECTION_VIEW, IMAGE_VIEW, HUD_VIEW, MAP_VIEW, 
        MAIN_MENU_WINDOW, GAME_PLAY_WINDOW
	};
    
    View(int xStart, int yStart, int xEnd, int yEnd);

    void addView(View* view);
	std::vector<View*> getViews();
    
	virtual ~View();
	virtual Type getType() = 0;

protected:
    int xStart, yStart, xEnd, yEnd;
	std::vector<View*> views;
    
};

} /* namespace graphic */
#endif /* VIEW_HPP_ */
