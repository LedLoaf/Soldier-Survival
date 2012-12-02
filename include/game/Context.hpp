#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include <view/window/Window.hpp>
#include <util/Resource.hpp>


namespace game {

class Context {
public:
	void setActiveWindow(view::Window* window);
	view::Window* getActiveWindow();
    util::Resource* getResourceManager(); 
    
private:
	view::Window* activeWindow;
};

}

#endif














