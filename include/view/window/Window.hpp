#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <view/View.hpp>
#include <util/DeviceManager.hpp>
#include <vector>
#include <iostream>
#include <util/Key.hpp>
#include <util/Location.hpp>



namespace view {

class Window : public view::View {
public:
    Window(int xStart, int yStart, int xEnd, int yEnd);
    virtual ~Window();

	bool hasSubWindow();
	void setSubWindow(Window* window);
    Window* getSubWindow();
    
	virtual Type getType() = 0;
	virtual void onArrowPressed(util::Location::Vector vector) = 0;
	virtual void onEnterPressed() = 0;
    virtual void onEscPressed();
    void addUnusedView(view::View* unusedView);
    std::vector<view::View*>* getUnusedViews();
    

protected:
//	WindowModel model;
	Window* subWindow;
    std::vector<view::View>* unusedViews;
};

}
#endif
