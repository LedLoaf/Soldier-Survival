#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <view/View.hpp>
#include <util/DeviceManager.hpp>

namespace view {

class Window : View {
private:
	WindowModel model;

public:
	Window(int x, int y, int width, int height) {
		
	}

	Window() : View(0, 0, util::DeviceManager::getScreenWidth(), util::DeviceManager::getScreenHeight()) {
	}

	void addView(View& view) {
		views.add(view);
	}

	void getViews() {
		return views;
	}


};

}
#endif
