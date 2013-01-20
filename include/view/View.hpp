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
		SELECTION_VIEW, IMAGE_VIEW, TEXT_VIEW, HUD_VIEW, MAP_VIEW, MINI_MAP_VIEW, WAR_VIEW,
        MAIN_MENU_WINDOW, GAME_PLAY_WINDOW, PAUSE_WINDOW
	};
    
    enum Orientation {
        HORIZONTAL, VERTICAL
    };
    
    View(int xStart, int yStart, int xEnd, int yEnd);

    util::Location::Position getStartPosition();
    util::Location::Position getEndPosition();
    
    bool hasViews();
    void addView(View* view);
    void removeView(View* view);
    
	std::vector<View*> getViews();
    
	virtual ~View();
	virtual Type getType() = 0;

    void pause();
    bool isPaused();
    void resume();
    
protected:
    int xStart, yStart, xEnd, yEnd;
	std::vector<View*> views;
    bool paused;
    
};

} /* namespace graphic */
#endif /* VIEW_HPP_ */
