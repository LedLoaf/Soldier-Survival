#include <view/window/Window.hpp>
#include <view/window/GamePlayWindow.hpp>
#include <game/Application.hpp>

namespace view {

GamePlayWindow::GamePlayWindow(game::LevelDescription* levelDescription) : Window(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
        game::Application::getInstance().getDeviceManager()->getScreenWidth())  { 
    
    this->levelDescription = levelDescription;

//    this->mapView = new MapView(0, 200, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
//            game::Application::getInstance().getDeviceManager()->getScreenHeight() - 200);
//    this->mapView->generateLevel(levelDescription);
    
    
//		this.miniMapWindow = new MiniMapWindow();

//      this.player = mapHandler->getPlayer();

    initUI();
}


void GamePlayWindow::initUI() {
    hudView = new HUDView(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 100);
   
    
	addView(hudView);
    

}


void GamePlayWindow::onArrowPressed(util::Key::Arrow arrow) {
//	if (arrow == util::Key::UP) {
//		if (selectionView->hasPreviousElement())
//			selectionView->selectPreviousElement();
//	} else if (arrow == util::Key::DOWN) {
//		if (selectionView->hasNextElement())
//			selectionView->selectNextElement();
//	}


}


void GamePlayWindow::onEnterPressed() {
//	Util::Action optionAction = selectionView->getSelectedElement()->getAction();
//
//	if (optionAction == Util::RUN_LEVEL_SELECTION)
//			game::Application::getInstance().getGameEngine()->runLevelSelection();
//    else if(optionAction == Util::RUN_EXIT)
//			game::Application::getInstance().getGameEngine()->onExitGameRequest();
	
}

View::Type GamePlayWindow::getType() {
    return View::GAME_PLAY_WINDOW;
}

}
