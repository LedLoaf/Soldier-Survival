#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <SFML/Window.hpp>
#include <game/SFMLEventHandler.hpp>
#include <graphic/SFMLAbstractGraphicEngine.hpp>
#include <game/GameMasterEngine.hpp>
#include <game/Context.hpp>

namespace game {

class Application {

public:
	static Application* create(int width, int height);
	static Application& Application::getInstance();
	void run();
	bool isRunning();
	void setEventHandler(SFMLEventHandler* eventHandler);
	void setGameEngine(GameMasterEngine* gameEngine);
	void setGraphicEngine(graphic::SFMLAbstractGraphicEngine* graphicEngine);

	GameMasterEngine& getGameEngine();

	void processEvent();
	void display();

	Context& getContext();

private:
	static Application* instance;


	sf::RenderWindow* renderWindow;
	Context& context;

	int width;
	int height;

	Application(int width, int height);

};

}

#endif

