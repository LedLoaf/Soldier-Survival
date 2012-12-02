#include <graphic/SFMLAbstractGraphicEngine.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace graphic {

std::vector<sf::Sprite*> SFMLAbstractViewPainter::getSprites() {
	return sprites;
}

}
