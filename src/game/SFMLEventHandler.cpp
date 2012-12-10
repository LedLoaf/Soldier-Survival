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
				case sf::Key::Right :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Key::RIGHT);
					break;      
				case sf::Key::Up :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Key::UP);
					break;        
				case sf::Key::Down :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Key::DOWN);
					break;         
                    
				case sf::Key::Return :
					Application::getInstance().getContext()->getActiveWindow()->onEnterPressed();
					break;                        
			}
            
        if (Event.Type == sf::Event::Closed)
//                Application::getInstance().getGameEngine()->onExitGameRequest();
                Application::getInstance().getContext()->getActiveWindow()->onEscPressed();
	}

}

void SFMLEventHandler::setEventInput(sf::RenderWindow* renderWindow) {
	this->renderWindow = renderWindow;
}

