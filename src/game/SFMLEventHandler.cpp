#include <game/SFMLEventHandler.hpp>
#include <game/Application.hpp>

#include <util/Location.hpp>

using namespace game;

void SFMLEventHandler::processEvent() {
    sf::Event Event;

	while (renderWindow->GetEvent(Event)) {
		if (Event.Type == sf::Event::KeyPressed)

			switch(Event.Key.Code) {
				case sf::Key::Left :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Location::LEFT);
					break;
				case sf::Key::Right :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Location::RIGHT);
					break;      
				case sf::Key::Up :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Location::UP);
					break;        
				case sf::Key::Down :
					Application::getInstance().getContext()->getActiveWindow()->onArrowPressed(util::Location::DOWN);
					break;         
				case sf::Key::Return :
					Application::getInstance().getContext()->getActiveWindow()->onEnterPressed();
					break;           
                case sf::Key::Space :
                    Application::getInstance().getContext()->getActiveWindow()->onSpacePressed();
                    break;
                case sf::Key::F :
                    Application::getInstance().getContext()->getActiveWindow()->onCharacterPressed('f');
                    break;
                case sf::Key::V :
                    Application::getInstance().getContext()->getActiveWindow()->onCharacterPressed('v');
                    break;  
                case sf::Key::Q :
                    Application::getInstance().getContext()->getActiveWindow()->onCharacterPressed('q');
                    break;                                  
                case sf::Key::M :
                    Application::getInstance().getContext()->getActiveWindow()->onCharacterPressed('m');
                    break;                       
                case sf::Key::Escape :
                    Application::getInstance().getContext()->getActiveWindow()->onEscPressed();
			}
            
        if (Event.Type == sf::Event::Closed)
//                Application::getInstance().getGameEngine()->onExitGameRequest();
                Application::getInstance().getContext()->getActiveWindow()->onEscPressed();
	}

}

void SFMLEventHandler::setEventInput(sf::RenderWindow* renderWindow) {
	this->renderWindow = renderWindow;
}

