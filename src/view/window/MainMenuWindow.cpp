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
	selectionView = new SelectionView(100, 100, 150, 400);
    selectionView->setSelectionModel(selectionViewModel);
    
	addView(selectionView);


//	mainMenuLogoPath = Application.getResourceManager().getPath(Resource.MAIN_MENU_LOGO);
//
//	addView(new ImageView(100, 0, 150, 200, mainMenuLogoPath));
}


void MainMenuWindow::onArrowPressed(util::Key::Arrow arrow) {
	if (arrow == util::Key::DOWN) {
		if (selectionView->hasNextElement())
			selectionView->selectNextElement();
	}


}


void MainMenuWindow::onEnterPressed() {
//	Util::Action optionAction = selectionView->getSelectedElement()->getAction();
//
//	if (optionAction == Util::RUN_LEVEL_SELECTION)
//			game::Application::getInstance().getGameEngine()->runLevelSelection();
//    else if(optionAction == Util::RUN_EXIT)
//			game::Application::getInstance().getGameEngine()->exitGame();
	
}

View::Type getType() {
    return View::MAIN_MENU_WINDOW;
}


}
