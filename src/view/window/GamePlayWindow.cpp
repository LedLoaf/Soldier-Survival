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
    
    initUI();
}


void GamePlayWindow::initUI() {
    
    hudView = new HUDView(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 100, levelGenerator->getHUDViewModel());
	addView(hudView);
  
    
    mapView = new MapView(0, 100, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
            game::Application::getInstance().getDeviceManager()->getScreenHeight());
    
    MapViewModel* mapViewModel = levelGenerator->getMapViewModel();
    mapViewModel->setMapView(mapView);
    
    mapView->setModel(mapViewModel);
    mapView->beginCharactersLife();
	addView(mapView);
    
    
//    miniMapView = new MiniMapView(hudView->getEndPosition().getX(), hudView->getStartPosition().getY(), 
//            game::Application::getInstance().getDeviceManager()->getScreenWidth(), hudView->getStartPosition().getY());
//    miniMapView->setMapModel(mapViewModel);
//    addView(miniMapView);    

}


void GamePlayWindow::onArrowPressed(util::Location::Vector vector) {
    if (hasSubWindow())
        subWindow->onArrowPressed(vector);
    else {
        if (mapView->canMoveCharacter(mapView->getPlayer(), vector))
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
    else 
        game::Application::getInstance().getGameEngine()->pauseGame();
    
}

View::Type GamePlayWindow::getType() {
    return View::GAME_PLAY_WINDOW;
}

void GamePlayWindow::pause() {
//    hudView->pause();
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
