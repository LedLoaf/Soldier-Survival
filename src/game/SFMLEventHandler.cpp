#include <game/SFMLEventHandler.hpp>


void SFMLEventHandler::processEvent() {
    sf::Event Event;

	while (renderWindow.GetEvent) {
		if (Event.Type == sf::Event::KeyPressed)

			switch(Event.Key.Code) {
				case: sf::Key::Left
					application->getGameEngine()->onLeftArrowPressed();
			}
	}

}

