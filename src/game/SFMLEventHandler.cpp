#include <game/SFMLEventHandler.hpp>
#include <game/Application.hpp>

#include "util/Key.hpp"

using namespace game;

void SFMLEventHandler::processEvent() {
    sf::Event Event;

	while (renderWindow->GetEvent(Event)) {
		if (Event.Type == sf::Event::KeyPressed)

			switch(Event.Key.Code) {
				case sf::Key::Left :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Key::LEFT);
					break;
			}
            
        if (Event.Type == sf::Event::Closed)
                Application::getInstance().getRenderWinow()->Close();
	}

}

void SFMLEventHandler::setEventInput(sf::RenderWindow* renderWindow) {
	this->renderWindow = renderWindow;
}

