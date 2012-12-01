#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <view/View.hpp>
#include <util/DeviceManager.hpp>
#include <list>
#include <iostream>

namespace view {

class Window : view::View {
public:
	Window() : View(0, 0, util::DeviceManager::getScreenWidth(), util::DeviceManager::getScreenHeight()) {
	}


	void addView(View& view);
	std::list<View&> getViews();
	bool hasSubWindow();
	void setSubWindow(Window& window);

private:
//	WindowModel model;
	std::list<View&> views;
	Window& subWindow;

};

}
#endif
