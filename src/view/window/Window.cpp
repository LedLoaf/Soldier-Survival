#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <list>

namespace view {

Window::Window(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {}
    
void Window::addView(View* view) {
	views.push_back(view);
}

std::vector<View*> Window::getViews() {
	return views;
}

bool Window::hasSubWindow() {
	if (subWindow)
		return true;
	else
		return false;
}

void Window::setSubWindow(Window* window) {
	subWindow = window;
}
}
