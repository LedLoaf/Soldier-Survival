#include <algorithm>

#include <view/View.hpp>

#include "game/Application.hpp"

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
    int size = views.size();
	views.push_back(view);
}

void View::removeView(View* view) {
    View *v = view;
    
    for (int i = 0; i < views.size(); i++)
        if (views[i] == view)
            views.erase(views.begin() + i);
    
    
    view = NULL;
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
    paused = false;
}


} /* namespace graphic */
