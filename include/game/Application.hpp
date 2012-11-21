#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SFML/Window.hpp>


class Application {

public:
	static Application* create(int width, int height);
	static Application* Application::getInstance();
	bool isRunning();
	void setEventHandler(EventHandler* eventHandler);


private:
	static Application* instance;

	sf::RenderWindow* renderWindow;
	int width;
	int height;

	Application(int width, int height);

};

#endif

