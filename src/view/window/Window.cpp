#include <game/Application.hpp>
#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <list>

namespace view {

Window::Window(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
    subWindow = NULL;
    game::Application::getInstance().getContext()->setActiveWindow(this);
}

Window::~Window() {
    delete subWindow;
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

Window* Window::getSubWindow() {
	return subWindow;
}

void Window::onEscPressed() {
}

void Window::onCharacterPressed(char c) {
    
}

void Window::onSpacePressed() {
    
}


}
