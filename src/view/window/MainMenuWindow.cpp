#include <view/window/MainMenuWindow.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <view/SelectionView.hpp>
#include <game/Application.hpp>

namespace view {

void MainMenuWindow::initModel() {
	selectionViewModel = new SelectionViewModel();
}

void MainMenuWindow::initUI() {
	// x, y, width, height, model
	selectionView = new SelectionView(100, 100, 150, 400, selectionViewModel);
	addView(mainMenuSelectionView);


//	mainMenuLogoPath = Application.getResourceManager().getPath(Resource.MAIN_MENU_LOGO);
//
//	addView(new ImageView(100, 0, 150, 200, mainMenuLogoPath));
}


void MainMenuWindow::onArrowPressed(util::Key::Arrow arrow) {
	if (arrow == util::Key::DOWN) {
		if (selectionView.hasNextElement())
			selectionView.selectNextElement()();
	}


}


void MainMenuWindow::onEnterPressed() {
	util::Action optionAction = selectionView.getSelectedElement().getAction();

	switch(optionAction) {
		case util::Action::RUN_LEVEL_SELECTION:
			game::Application::getInstance().getGameEngine().runLevelSelection();
			break;
		case util::Action::RUN_EXIT:
			game::Application::getInstance().getGameEngine().exitGame();
			break;
	}
}

}
