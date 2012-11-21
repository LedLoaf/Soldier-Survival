#include <game/Application.hpp>
#include <game/GameMasterEngine.hpp>




int main() {
	Application* app = Application::create(800, 600);


	game::GameMasterEngine gameEngine = new GameMasterEngine();

	app.setEventHandler(new game::SFMLEventHandler(app));
	app.setGameEngine(new game::GameMasterEngine(app));
	app.setGraphicEngine(new graphic::BasicGraphicEngine(app));


	app.run();


	while (app.isRunning()) {
		app->processEvent();
		app->display();
	}


	return 0;
}
