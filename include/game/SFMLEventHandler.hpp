
#ifndef SFML_EVENT_HANDLER_HPP_
#define SFML_EVENT_HANDLER_HPP_

#include <game/IEventHandler.hpp>

namespace game {

class SFMLEventHandler : IEventHandler {

public:
	void processEvent();
	void setEventInput(sf::RenderWindow* renderWindow);

private:
	sf::RenderWindow* renderWindow;
};

}

#endif
