#ifndef PAUSE_WINDOW_HPP_
#define PAUSE_WINDOW_HPP_

#include <iostream>
#include <list>

#include <view/View.hpp>
#include <view/window/Window.hpp>
#include <view/SelectionView.hpp>
#include <util/Key.hpp>

namespace view {

class PauseWindow : public Window {
public:
	PauseWindow(Window* parentWindow);
	void initUI();

	virtual void onArrowPressed(util::Location::Vector vector);
	virtual void onEnterPressed() ;
    virtual void onEscPressed();
    virtual void onCharacterPressed(char c);
    virtual void onSpacePressed();
    
	virtual Type getType();


private:
	SelectionViewModel* selectionViewModel;
	SelectionView* selectionView;

};

}
#endif
