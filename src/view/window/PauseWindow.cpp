#include <view/window/PauseWindow.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <view/SelectionView.hpp>
#include <view/ImageView.hpp>
#include <game/Application.hpp>

#include <util/Util.hpp>
#include <util/Resource.hpp>

namespace view {

PauseWindow::PauseWindow(Window* parentWindow) : Window(game::Application::getInstance().getDeviceManager()->getScreenWidth() / 2, 
        game::Application::getInstance().getDeviceManager()->getScreenHeight() / 2, 
        game::Application::getInstance().getDeviceManager()->getScreenWidth() + 100, 
        game::Application::getInstance().getDeviceManager()->getScreenHeight() + 100)  { 
    
    this->parentWindow = parentWindow;
    initUI();
}


void PauseWindow::initUI() {       
	selectionView = new SelectionView(0, 0, 200, 500, SelectionViewModel::SIMPLE_PAUSE_MENU);
    selectionView->setOrientation(view::View::HORIZONTAL);
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RESUME_GAME));    
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RETURN_TO_MAIN_MENU));
    
    selectionView->selectElement(0);
    
	addView(selectionView);

}

void PauseWindow::onArrowPressed(util::Location::Vector vector) {
	if (vector == util::Location::LEFT) {
		if (selectionView->hasPreviousElement())
			selectionView->selectPreviousElement();
	} else if (vector == util::Location::RIGHT) {
		if (selectionView->hasNextElement())
			selectionView->selectNextElement();
	}


}


void PauseWindow::onEnterPressed() {
	util::Util::Action optionAction = selectionView->getSelectedElement()->getAction();

	if (optionAction == util::Util::RESUME_GAME) 
			game::Application::getInstance().getGameEngine()->resumeGame();
    else if(optionAction == util::Util::RETURN_TO_MAIN_MENU)
			game::Application::getInstance().getGameEngine()->run();
	
}

void PauseWindow::onEscPressed() {
    parentWindow->setSubWindow(NULL);
    
    game::Application::getInstance().getGameEngine()->resumeGame();
}

void PauseWindow::onCharacterPressed(char c) {
    
}

void PauseWindow::onSpacePressed() {
    
}

View::Type PauseWindow::getType() {
    return View::PAUSE_WINDOW;
}


}
