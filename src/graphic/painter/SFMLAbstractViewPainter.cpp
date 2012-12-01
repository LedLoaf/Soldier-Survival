#include <graphic/SFMLAbstractGraphicEngine.hpp>
#include <SFML/Graphics/Sprite.hpp>


using namespace view;


std::list<sf::Sprite&> AbstractViewPainter::getSprites() {
	return sprites;
}
