#ifndef SFML_ABSTRACT_VIEW_PAINTER_HPP_
#define SFML_ABSTRACT_VIEW_PAINTER_HPP_

#include <SFML/Graphics/Sprite.hpp>
#include <map>

namespace graphic {

class SFMLAbstractViewPainter {
public:
	SFMLAbstractViewPainter();
	virtual ~SFMLAbstractViewPainter();

	virtual void init() = 0;
	virtual void update() = 0;

	std::map<int, sf::Sprite&> getSprites();


protected:
	std::map<int, sf::Sprite&> sprites;
};

}
#endif
