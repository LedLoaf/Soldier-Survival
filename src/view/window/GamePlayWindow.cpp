#include <view/window/Window.hpp>
#include <view/window/GamePlayWindow.hpp>
#include <view/window/PauseWindow.hpp>
#include <game/Application.hpp>

#include "util/SFMLAmazinResource.hpp"

namespace view {

GamePlayWindow::GamePlayWindow(game::LevelDescription* levelDescription) : Window(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
        game::Application::getInstance().getDeviceManager()->getScreenWidth())  { 
    
    this->levelDescription = levelDescription;

//    this->mapView = new MapView(0, 200, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
//            game::Application::getInstance().getDeviceManager()->getScreenHeight() - 200);
//    this->mapView->generateLevel(levelDescription);
    
    
//		this.miniMapWindow = new MiniMapWindow();

//      this.player = mapHandler->getPlayer();
    
    this->levelGenerator = new game::LevelGenerator(levelDescription);
    
    initUI();
}


void GamePlayWindow::initUI() {
    
    hudView = new HUDView(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 100);
    hudView->setHUDModel(levelGenerator->getHUDViewModel());
	addView(hudView);
  
    
    mapView = new MapView(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 100);
    mapView->setMapModel(levelGenerator->getMapViewModel());
	addView(mapView);
    
    
    miniMapView = new MiniMapView(hudView->getEndPosition()->getX(), hudView->getStartPosition()->getY(), 
            game::Application::getInstance().getDeviceManager()->getScreenWidth(), hudView->getStartPosition()->getY());
    mapView->setMapModel(levelGenerator->getMapViewModel());
    addView(miniMapView);
}


void GamePlayWindow::onArrowPressed(util::Key::Arrow arrow) {
    Window::onArrowPressed(arrow);
    
    if (hasSubWindow())
        subWindow->onArrowPressed(arrow);
    else {
        SelectionView* weaponSelectionView = hudView->getWeaponSelectionView();
        if (arrow == util::Key::UP) {
            if (weaponSelectionView->hasPreviousElement())
                weaponSelectionView->selectPreviousElement();
        } else if (arrow == util::Key::DOWN) {
            if (weaponSelectionView->hasNextElement())
                weaponSelectionView->selectNextElement();
        }
    }
}


void GamePlayWindow::onEnterPressed() {
    if (hasSubWindow())
        subWindow->onEnterPressed();
    else {
    
    }
//	Util::Action optionAction = selectionView->getSelectedElement()->getAction();
//
//	if (optionAction == Util::RUN_LEVEL_SELECTION)
//			game::Application::getInstance().getGameEngine()->runLevelSelection();
//    else if(optionAction == Util::RUN_EXIT)
//			game::Application::getInstance().getGameEngine()->onExitGameRequest();
	
}

void GamePlayWindow::onEscPressed() {
    if (hasSubWindow())
        subWindow->onEscPressed();
    else 
        game::Application::getInstance().getGameEngine()->pauseGame();
    
}

View::Type GamePlayWindow::getType() {
    return View::GAME_PLAY_WINDOW;
}

void GamePlayWindow::pause() {
    hudView->pause();
    mapView->pause();
    miniMapView->pause();
}

void GamePlayWindow::resume() {
    hudView->resume();
    mapView->resume();
    miniMapView->resume();    
}

}
