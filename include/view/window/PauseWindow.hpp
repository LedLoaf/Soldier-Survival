#ifndef PAUSE_WINDOW_HPP_
#define PAUSE_WINDOW_HPP_

#include <iostream>
#include <list>

#include <view/View.hpp>
#include <view/window/Window.hpp>
#include <view/SelectionView.hpp>
#include <util/Key.hpp>

#include <view/window/GamePlayWindow.hpp>

namespace view {

class PauseWindow : public Window {
public:
	PauseWindow(GamePlayWindow* gamePlayWindow);
	void initUI();

    GamePlayWindow* getParentWindow();
    
	virtual void onArrowPressed(util::Location::Vector vector);
	virtual void onEnterPressed() ;
    virtual void onEscPressed();
    virtual void onCharacterPressed(char c);
    virtual void onSpacePressed();
    
	virtual Type getType();


private:
    GamePlayWindow* gamePlayWindow;
	SelectionViewModel* selectionViewModel;
	SelectionView* selectionView;
    MiniMapView* miniMapView;
    
    

};

}
#endif
