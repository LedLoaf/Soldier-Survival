#include <view/window/PauseWindow.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <view/SelectionView.hpp>
#include <view/ImageView.hpp>
#include <game/Application.hpp>

#include <util/Util.hpp>
#include <util/Resource.hpp>

#include "view/window/GamePlayWindow.hpp"

namespace view {

PauseWindow::PauseWindow(GamePlayWindow* gamePlayWindow) : Window(0, 0,
        game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
        game::Application::getInstance().getDeviceManager()->getScreenHeight())  { 
    
    this->gamePlayWindow = gamePlayWindow;
    initUI();
}


void PauseWindow::initUI() {       
//	selectionView = new SelectionView(0, 0, 200, 500, SelectionViewModel::SIMPLE_PAUSE_MENU);
//    selectionView->setOrientation(view::View::HORIZONTAL);
//    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RESUME_GAME));    
//    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RETURN_TO_MAIN_MENU));
//    
//    selectionView->selectElement(0);
//    
//	addView(selectionView);
    
    miniMapView = new MiniMapView(xStart + 100, yStart, xEnd - 100, yEnd);
    miniMapView->setMapModel(gamePlayWindow->getMapView()->getModel());
    addView(miniMapView);        
}

GamePlayWindow* PauseWindow::getParentWindow() {
    return gamePlayWindow;
}


void PauseWindow::onArrowPressed(util::Location::Vector vector) {
}


void PauseWindow::onEnterPressed() {
}

void PauseWindow::onEscPressed() {

}

void PauseWindow::onCharacterPressed(char c) {
    gamePlayWindow->setSubWindow(NULL);
    
    game::Application::getInstance().getGameEngine()->resumeGame();    
}

void PauseWindow::onSpacePressed() {
    
}

View::Type PauseWindow::getType() {
    return View::PAUSE_WINDOW;
}


}
