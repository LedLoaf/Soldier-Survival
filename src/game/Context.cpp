#include <view/window/Window.hpp>


namespace game {

void Context::setActiveWindow(view::Window& window) {
	activeWindow = window;
}


view::Window& Context::getActiveWindow() {
	return activeWindow;
}

}
