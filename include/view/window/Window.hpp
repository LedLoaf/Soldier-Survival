#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <view/View.hpp>
#include <util/DeviceManager.hpp>
#include <vector>
#include <iostream>
#include <util/Key.hpp>

namespace view {

class Window : public view::View {
public:
    Window(int xStart, int yStart, int xEnd, int yEnd);
    
	void addView(View* view);
	std::vector<View*> getViews();
	bool hasSubWindow();
	void setSubWindow(Window* window);
	virtual Type getType() = 0;
	virtual void onArrowPressed(util::Key::Arrow arrow) = 0;
	virtual void onEnterPressed() = 0;
    
    

protected:
//	WindowModel model;
	std::vector<View*> views;
	Window* subWindow;

};

}
#endif
