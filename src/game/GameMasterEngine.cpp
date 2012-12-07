#include <game/GameMasterEngine.hpp>
#include <game/object/LevelDescription.hpp>
#include <view/window/MainMenuWindow.hpp>

#include "game/Application.hpp"

using namespace view;

namespace game {

void GameMasterEngine::run() {
	// show main menu
	MainMenuWindow *mainMenuWindow = new MainMenuWindow();
	Application::getInstance().getContext()->setActiveWindow(mainMenuWindow);
}

void GameMasterEngine::runLevelSelection() {

}

/*
	Uruchamia dany poziom opisany (poziom trudnosci, postacie, itd) przez LevelDescription

	Metoda wywolywana po wyborze levelu w menu
*/
void GameMasterEngine::runLevel(LevelDescription& levelDescription) {
	// tworzone jest nowe okno, ktore jest rysowane.
	// w GamePlayWindow mapGenerator generuje poziom z informacji w obiekcie LevelDescription
//
//	// okno wyboru levelu jest niszczone
//	~context->getActiveWindow();
//
//	context->setActiveWindow(new GamePlayWindow(levelDescription));
}


void GameMasterEngine::pauseLevel() {
	// pausa na mapie.
	// pausa na czasie gry
//
//	PauseWindow pauseWindow = new PauseWindow(); 
//	// w tym momencie okno jest juz narysowane nad mapa, hudem, itd.
//	pauseWindow.setParent(context->getActiveWindow()); // GamePlayWindow;
//
//	context->setActiveWindow(pauseWindow);
}

void GameMasterEngine::resumeLevel() {
	
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

void GameMasterEngine::onExitGameRequest() {
    if (Application::getInstance().getContext()->getActiveWindow()->getType() == view::View::MAIN_MENU_WINDOW)
        Application::getInstance().exit();
}


}










