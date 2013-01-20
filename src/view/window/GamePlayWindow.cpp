#include <view/ImageView.hpp>
#include <view/TextView.hpp>
#include <view/window/Window.hpp>
#include <view/window/GamePlayWindow.hpp>
#include <view/window/PauseWindow.hpp>
#include <game/Application.hpp>

#include "util/SFMLAmazinResource.hpp"
#include "game/LevelGenerator.hpp"
#include "game/WarManager.hpp"


namespace view {

GamePlayWindow::GamePlayWindow(game::LevelDescription* levelDescription) : mapView(NULL), Window(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
        game::Application::getInstance().getDeviceManager()->getScreenWidth())  { 

    this->levelDescription = levelDescription;
    this->levelGenerator = new game::LevelGenerator(levelDescription);
    this->isGameOver = false;
    
    initUI();
}

GamePlayWindow::~GamePlayWindow() {
    delete hudView;
	delete mapView;
    delete levelDescription;
    delete levelGenerator;
}

void GamePlayWindow::gameOver() {
    isGameOver = true;
    pause();

    addView(new TextView(game::Application::getInstance().getDeviceManager()->getScreenHeight() / 2, 
            game::Application::getInstance().getDeviceManager()->getScreenHeight() / 2, 
            500, game::Application::getInstance().getDeviceManager()->getScreenHeight() - 50, "Game over. Press esc to exit.", TextView::MIDDLE));    
}

void GamePlayWindow::initUI() {
    
    hudView = new HUDView(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 100, levelGenerator->getHUDViewModel());
	addView(hudView);
    
	addView(new ImageView(game::Application::getInstance().getDeviceManager()->getScreenWidth() - 200, 0, 
            100, game::Application::getInstance().getDeviceManager()->getScreenWidth(), util::Resource::GAME_PLAY_LOGO));        
  
    
    mapView = new MapView(0, 100, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
            game::Application::getInstance().getDeviceManager()->getScreenHeight());
    
    MapViewModel* mapViewModel = levelGenerator->getMapViewModel();
    mapViewModel->setMapView(mapView);
    
    mapView->setModel(mapViewModel);
    mapView->beginCharactersLife();
	addView(mapView);
    
}


void GamePlayWindow::onArrowPressed(util::Location::Vector vector) {
    if (hasSubWindow())
        subWindow->onArrowPressed(vector);
    else {
        if (!isGameOver && mapView->canMoveCharacter(mapView->getPlayer(), vector))
        mapView->moveCharacter(mapView->getPlayer(), vector);
    }
    
    
//    else {
//        SelectionView* weaponSelectionView = hudView->getWeaponSelectionView();
//        if (arrow == util::Key::UP) {
//            if (weaponSelectionView->hasPreviousElement()) {
//                weaponSelectionView->selectPreviousElement();
//                mapView->getPlayer()->
//                        setCurrentWeapon(dynamic_cast<view::SelectionViewModel::WeaponSelectableElement*>
//                            (weaponSelectionView->getSelectedElement())->getWeapon());
//            }
//        } else if (arrow == util::Key::DOWN) {
//            if (weaponSelectionView->hasNextElement())
//                weaponSelectionView->selectNextElement();
//                mapView->getPlayer()->
//                        setCurrentWeapon(dynamic_cast<view::SelectionViewModel::WeaponSelectableElement*>
//                            (weaponSelectionView->getSelectedElement())->getWeapon());                
//        }
//    }
}

void GamePlayWindow::onCharacterPressed(char c) {
    if (hasSubWindow())
        subWindow->onCharacterPressed(c); 
    else {
        switch (c) {
            case 'v':
                hudView->switchToNextWeapon();
                break;
            case 'f':
                hudView->switchToPreviousWeapon();
                break;
            case 'm':           
                pause();
                PauseWindow* pauseWindow = new PauseWindow(this);
                subWindow = pauseWindow;    
                break;
        }
    }
}

void GamePlayWindow::onSpacePressed() {
    if (!mapView->checkIfBombHasBeenPlanted())
        mapView->tryToPlantBomb();
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
    else {
        game::Application::getInstance().getGameEngine()->exitGame();
    }
    
}

View::Type GamePlayWindow::getType() {
    return View::GAME_PLAY_WINDOW;
}

void GamePlayWindow::pause() {
    hudView->pause();
    mapView->pause();
//    miniMapView->pause();
}

void GamePlayWindow::resume() {
    hudView->resume();
    mapView->resume();
//    miniMapView->resume();    
}

MapView* GamePlayWindow::getMapView() {
    return mapView;
}

}
