#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <view/View.hpp>
#include <util/DeviceManager.hpp>
#include <vector>
#include <iostream>

namespace view {

class Window : public view::View {
public:
	Window() : View(0, 0, util::DeviceManager::getScreenWidth(), util::DeviceManager::getScreenHeight()) {}


	void addView(View* view);
	std::vector<View*> getViews();
	bool hasSubWindow();
	void setSubWindow(Window* window);
	virtual Type getType() = 0;
    

protected:
//	WindowModel model;
	std::vector<View*> views;
	Window* subWindow;

};

}
#endif
