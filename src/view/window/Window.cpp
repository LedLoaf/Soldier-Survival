#include <view/window/Window.hpp>
#include <list>

namespace view {

void Window::addView(View& view) {
	views.push_back(view);
}

std::list<View&> Window::getViews() {
	return views;
}

bool Window::hasSubWindow() {
	if (subWindow)
		return true;
	else
		return false;
}

void Window::setSubWindow(Window& window) {
	subWindow = window;
}
}
