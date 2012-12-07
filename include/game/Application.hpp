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
	static Application& getInstance();
    
	void run();
	bool isRunning();
    void exit();
    
	void setEventHandler(SFMLEventHandler* eventHandler);
	void setGameEngine(GameMasterEngine* gameEngine);
	void setGraphicEngine(graphic::SFMLAbstractGraphicEngine* graphicEngine);

	GameMasterEngine* getGameEngine();

    sf::RenderWindow* getRenderWinow();
    
    util::DeviceManager* getDeviceManager();
    
	void processEvent();
	void display();

	Context* getContext();

private:
	static Application* instance;


	sf::RenderWindow* renderWindow;
    SFMLEventHandler* eventHandler;
    GameMasterEngine* gameEngine;
    graphic::SFMLAbstractGraphicEngine* graphicEngine;
    
    Context* context;
    util::DeviceManager* deviceManager;
    
	int width;
	int height;
    bool running;

	Application(int width, int height);

};

}

#endif

