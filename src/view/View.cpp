/*
 * View.cpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#include <view/View.hpp>

namespace view {

View::View(int xStart, int yStart, int xEnd, int yEnd) {
    this->xStart = xStart;
    this->xEnd = xEnd;
    
    this->yStart = yStart;
    this->yEnd = yEnd;
}  
    
View::~View() {
	// TODO Auto-generated destructor stub
}

util::Location::Position View::getStartPosition() {
    return util::Location::Position(xStart, yStart);
}

util::Location::Position View::getEndPosition() {
    return util::Location::Position(xEnd, yEnd);
}

util::Location::Position getEndPosition();

bool View::hasViews() {
    if (views.size() > 0)
        return true;
    else
        return false;
}


void View::addView(View* view) {
	views.push_back(view);
}

std::vector<View*> View::getViews() {
	return views;
}

void View::pause() {
    paused = true;
}

bool View::isPaused() {
    return paused;
}

void View::resume() {
    paused = false
}

} /* namespace graphic */
