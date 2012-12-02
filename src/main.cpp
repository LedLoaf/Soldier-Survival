#include <cstddef> //do poprawnej kompilacji SFML //(NULL)

#include <game/Application.hpp>
#include <game/GameMasterEngine.hpp>
#include <graphic/amazin/SFMLAmazinGraphicEngine.hpp>


using namespace game;


int main() {
	Application* app = Application::create(800, 600);


	app->setEventHandler(new game::SFMLEventHandler());
//	app->setGameEngine(new game::GameMasterEngine());
	app->setGraphicEngine(new graphic::amazin::SFMLAmazinGraphicEngine());
    
    
	app->run();


	while (app->isRunning()) {
		app->processEvent();
		app->display();
	}



	return 0;
}
