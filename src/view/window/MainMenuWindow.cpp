#include <view/window/MainMenuWindow.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <view/SelectionView.hpp>
#include <view/ImageView.hpp>
#include <view/TextView.hpp>
#include <game/Application.hpp>

#include <util/Util.hpp>
#include <util/Location.hpp>
#include <util/Resource.hpp>



namespace view {

MainMenuWindow::MainMenuWindow() : Window(0, 0, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
        game::Application::getInstance().getDeviceManager()->getScreenWidth())  { 
    initUI();
}

MainMenuWindow::~MainMenuWindow() {
    addUnusedView(selectionView);
    delete selectionView;
    
    delete mainMenuLogo;
    
    ViewModel* viewModel = selectionViewModel;
    selectionViewModel = NULL;
//    delete viewModel;
}


void MainMenuWindow::initUI() {
    mainMenuLogo = new ImageView(200, 10, 150, 200, util::Resource::MAIN_MENU_LOGO);
	addView(mainMenuLogo);    
    
    
	selectionView = new SelectionView(200, 200, 200, 500, SelectionViewModel::SIMPLE_MENU);
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_GAME_PLAY));    
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_LEVEL_SELECTION));
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_ABOUT));
    selectionView->addElement(new SelectionViewModel::SelectableElement(util::Util::RUN_EXIT));
    
    selectionView->selectElement(0);
    
	addView(selectionView);
    

    addView(new TextView(0, game::Application::getInstance().getDeviceManager()->getScreenHeight() - 50, 
            500, game::Application::getInstance().getDeviceManager()->getScreenHeight() - 50, "Soldier: Survival by 34fun team", TextView::SMALL));
}


void MainMenuWindow::onArrowPressed(util::Location::Vector vector) {
	if (vector == util::Location::UP) {
		if (selectionView->hasPreviousElement())
			selectionView->selectPreviousElement();
	} else if (vector == util::Location::DOWN) {
		if (selectionView->hasNextElement())
			selectionView->selectNextElement();
	}


}


void MainMenuWindow::onEnterPressed() {
	util::Util::Action optionAction = selectionView->getSelectedElement()->getAction();

	if (optionAction == util::Util::RUN_LEVEL_SELECTION)
		game::Application::getInstance().getGameEngine()->runLevelSelection();
    else if(optionAction == util::Util::RUN_EXIT)
		game::Application::getInstance().getGameEngine()->exitGame();
    else if(optionAction == util::Util::RUN_GAME_PLAY) {
        game::LevelDescription* sampleLevel = new game::LevelDescription(300, 300, 0.005, 9, 
            20, true, false, true, true, true, true);          
		game::Application::getInstance().getGameEngine()->runGamePlay(sampleLevel);
    }
	
}

void MainMenuWindow::onEscPressed() {
    game::Application::getInstance().getGameEngine()->exitGame();
}

void MainMenuWindow::onCharacterPressed(char c) {
    
}

void MainMenuWindow::onSpacePressed() {
    
}

View::Type MainMenuWindow::getType() {
    return View::MAIN_MENU_WINDOW;
}


}
