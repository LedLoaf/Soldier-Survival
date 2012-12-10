#include <view/window/PauseWindow.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <view/SelectionView.hpp>
#include <view/ImageView.hpp>
#include <game/Application.hpp>

#include <util/Util.hpp>
#include <util/Resource.hpp>

namespace view {

PauseWindow::PauseWindow() : Window(game::Application::getInstance().getDeviceManager()->getScreenWidth() / 2, 
        game::Application::getInstance().getDeviceManager()->getScreenHeight() / 2, 
        game::Application::getInstance().getDeviceManager()->getScreenWidth() + 100, 
        game::Application::getInstance().getDeviceManager()->getScreenHeight() + 100)  { 
    
    initUI();
}


void PauseWindow::initUI() {
//    std::string logoPath =
   
	addView(new ImageView(200, 10, 150, 200, util::Resource::MAIN_MENU_LOGO));    
    
	selectionView = new SelectionView(200, 200, 200, 500, SelectionViewModel::SIMPLE_MENU);
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_GAME_PLAY));    
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_LEVEL_SELECTION));
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_ABOUT));
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_EXIT));
    
    selectionView->selectElement(0);
    
	addView(selectionView);
    



}


void PauseWindow::onArrowPressed(util::Key::Arrow arrow) {

}


void PauseWindow::onEnterPressed() {

	
}

void PauseWindow::onEscPressed() {
    game::Application::getInstance().getGameEngine()->exitGame();
}


View::Type PauseWindow::getType() {
    return View::MAIN_MENU_WINDOW;
}


}
