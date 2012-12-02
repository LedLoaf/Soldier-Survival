#ifndef MAIN_MENU_WINDOW_HPP_
#define MAIN_MENU_WINDOW_HPP_

#include <iostream>
#include <list>

#include <view/View.hpp>
#include <view/window/Window.hpp>
#include <view/SelectionView.hpp>
#include <util/Key.hpp>

namespace view {

class MainMenuWindow : public Window {
public:
	MainMenuWindow();
	void initModel();
	void initUI();

	void onArrowPressed(util::Key::Arrow arrow);

	void onEnterPressed() ;
	virtual Type getType();


private:
	SelectionViewModel* selectionViewModel;
	SelectionView* selectionView;

};

}
#endif
