#ifndef MAIN_MENU_WINDOW_HPP_
#define MAIN_MENU_WINDOW_HPP_

#include <iostream>
#include <list>

#include <view/View.hpp>
#include <view/window/Window.hpp>
#include <util/Key.hpp>

namespace view {
    
class SelectionView;
class SelectionViewModel;
class ImageView;

class MainMenuWindow : public Window {
public:
	MainMenuWindow();
    virtual ~MainMenuWindow();
	void initUI();

	virtual void onArrowPressed(util::Location::Vector vector);
	virtual void onEnterPressed() ;
    virtual void onEscPressed();

	virtual Type getType();


private:
	SelectionViewModel* selectionViewModel;
	SelectionView* selectionView;
    
    ImageView* mainMenuLogo;

};

}
#endif
