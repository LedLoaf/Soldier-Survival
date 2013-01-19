#include <cstddef> //do poprawnej kompilacji SFML //(NULL)

#include <game/GameMasterEngine.hpp>
#include <game/object/LevelDescription.hpp>
#include <view/window/MainMenuWindow.hpp>

#include "game/Application.hpp"
#include "view/window/GamePlayWindow.hpp"
#include "view/window/PauseWindow.hpp"

using namespace view;

namespace game {

void GameMasterEngine::run() {
    MainMenuWindow *mainMenuWindow = new MainMenuWindow();
}

void GameMasterEngine::runLevelSelection() {
}

/*
	Uruchamia dany poziom opisany (poziom trudnosci, postacie, itd) przez LevelDescription

	Metoda wywolywana po wyborze levelu w menu
*/
void GameMasterEngine::runGamePlay(LevelDescription* levelDescription) {
    Window* previouslyActiveWindow = Application::getInstance().getContext()->getActiveWindow();
    GamePlayWindow *gamePlayWindow = new GamePlayWindow(levelDescription);
    
    for (int i = 0; i < previouslyActiveWindow->getViews().size(); i++)
        gamePlayWindow->addUnusedView(previouslyActiveWindow->getViews()[i]);
    
//	// okno wyboru levelu jest niszczone
	delete previouslyActiveWindow;
}


void GameMasterEngine::pauseGame() {
    Window* activeWindow = Application::getInstance().getContext()->getActiveWindow();
    activeWindow->pause();
//    activeWindow->setSubWindow(new PauseWindow());
}

void GameMasterEngine::resumeGame() {
    PauseWindow* pauseWindow = dynamic_cast<view::PauseWindow*>(Application::getInstance().getContext()->getActiveWindow());
    Application::getInstance().getContext()->setActiveWindow(pauseWindow->getParentWindow());
    
    
    for (int i = 0; i < pauseWindow->getViews().size(); i++)           
        Application::getInstance().getContext()->getActiveWindow()->addUnusedView(pauseWindow->getViews()[i]);
    delete pauseWindow;
    
    
    Application::getInstance().getContext()->getActiveWindow()->resume();
}



// Wywolywana np. po nacisnieciu 'powrot do gry' w oknie dialogowym przedstawiajacym pause
void GameMasterEngine::returnToGame() {
//	Window activeWindow = context->getActiveWindow();
//
//	Window parentWindow = activeWindow->getParent(); // tutaj teraz bedzie np. GamePlayWindow
//
//	~activeWindow(); // niszcze okno dialogowe przedstawiajace pause
//
//	context->setActiveWindow(parentWindow);
}

void GameMasterEngine::exitGame() {
        Application::getInstance().exit();
}


}










