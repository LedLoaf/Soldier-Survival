#include <game/SFMLEventHandler.hpp>
#include <game/Application.hpp>

using namespace game;

void SFMLEventHandler::processEvent() {
    sf::Event Event;

	while (renderWindow->GetEvent(Event)) {
		if (Event.Type == sf::Event::KeyPressed)

			switch(Event.Key.Code) {
				case sf::Key::Left :
					Application::getInstance().getGameEngine().onLeftArrowPressed();
					break;
			}
	}

}

void SFMLEventHandler::setEventInput(sf::RenderWindow* renderWindow) {
	this->renderWindow = renderWindow;
}

