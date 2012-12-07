#include <view/window/MainMenuWindow.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <view/SelectionView.hpp>
#include <view/ImageView.hpp>
#include <game/Application.hpp>

#include <util/Util.hpp>
#include <util/Resource.hpp>

namespace view {

MainMenuWindow::MainMenuWindow() : Window(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
        game::Application::getInstance().getDeviceManager()->getScreenWidth())  { 
    initUI();
}


void MainMenuWindow::initUI() {
	selectionView = new SelectionView(200, 200, 200, 500);
    selectionView->addElement(new SelectionViewModel::SelectableElement(Util::RUN_LEVEL_SELECTION));
    selectionView->addElement(new SelectionViewModel::SelectableElement(Util::RUN_ABOUT));

    selectionView->addElement(new SelectionViewModel::SelectableElement(Util::RUN_EXIT));
    
    selectionView->selectElement(0);
	addView(selectionView);


//    
//    std::string logoPath = game::Application::getInstance().getContext()->getResourceManager()->getPath(util::Resource::MAIN_MENU_LOGO);
//   
//	addView(new ImageView(100, 0, 150, 200, logoPath));
}


void MainMenuWindow::onArrowPressed(util::Key::Arrow arrow) {
	if (arrow == util::Key::UP) {
		if (selectionView->hasPreviousElement())
			selectionView->selectPreviousElement();
	} else if (arrow == util::Key::DOWN) {
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

View::Type MainMenuWindow::getType() {
    return View::MAIN_MENU_WINDOW;
}


}
