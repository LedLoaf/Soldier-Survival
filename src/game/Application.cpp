#include <game/Application.hpp>
#include <game/IEventHandler.hpp>
#include <SFML/Graphics.hpp>


static Application* Application::create(int width, int height) {
	instance = new Application(width, height);

	return instance;
}

static Application* Application::getInstance() {
	if (!instance) {
		// TODO: rzuc wyjatek, ze nie zostala stworzona
	}

	return instance;
}

Application::Application(int width, int height) {
	this->width = width;
	this->height = height;

	this->renderWindow = new sf::RenderWindow(sf::VideoMode(width, height, 32), "Soldier: Survival");
}

void Application::initResourceManager() {
	resourceManager = new ResourceManager.createFor(graphicEngine);
}


void setEventHandler(IEventHandler* eventHandler) {
	eventHandler->setEventInput(renderWindow);

	this->eventHandler = eventHandler;
}

void Application::processEvent() {
	this->eventHandler->processEvent();
}


