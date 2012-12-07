#include <graphic/SFMLAbstractGraphicEngine.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>

#include "util/Util.hpp"


namespace graphic {

std::vector<sf::Drawable*> SFMLAbstractViewPainter::getDrawables() {
	return drawables;
}



}
