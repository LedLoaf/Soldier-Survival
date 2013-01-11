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
//	// okno wyboru levelu jest niszczone
	delete Application::getInstance().getContext()->getActiveWindow();
    
    GamePlayWindow *gamePlayWindow = new GamePlayWindow(levelDescription);
}


void GameMasterEngine::pauseGame() {
    Window* activeWindow = Application::getInstance().getContext()->getActiveWindow();
    activeWindow->pause();
//    activeWindow->setSubWindow(new PauseWindow());
}

void GameMasterEngine::resumeGame() {
    Window* activeWindow = Application::getInstance().getContext()->getActiveWindow();
    activeWindow->resume();
//    ~activeWindow->getSubWindow();
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










