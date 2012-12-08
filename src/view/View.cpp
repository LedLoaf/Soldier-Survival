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

void View::addView(View* view) {
	views.push_back(view);
}

std::vector<View*> View::getViews() {
	return views;
}

} /* namespace graphic */
