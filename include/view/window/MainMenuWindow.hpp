#ifndef MAIN_MENU_WINDOW_HPP_
#define MAIN_MENU_WINDOW_HPP_

#include <iostream>
#include <list>

#include <view/window/Window.hpp>
#include <view/SelectionView.hpp>
#include <util/Key.hpp>

namespace view {

class MainMenuWindow : Window {
public:
	MainMenuWindow();
	void initModel();
	void initUI();

	void onArrowPressed(util::Key::Arrow arrow);

	void onEnterPressed() ;


private:
	SelectionViewModel& selectionViewModel;
	SelectionView& selectionView;

};

}
#endif
