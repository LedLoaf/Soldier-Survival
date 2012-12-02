#ifndef SFML_ABSTRACT_VIEW_PAINTER_HPP_
#define SFML_ABSTRACT_VIEW_PAINTER_HPP_

#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace graphic {

class SFMLAbstractViewPainter {
public:
//    virtual ~SFMLAbstractViewPainter();

	virtual void init() = 0;
	virtual void update() = 0;

	virtual std::vector<sf::Sprite*> getSprites() = 0;


protected:
//	std::map<int, sf::Sprite&> sprites;
    std::vector<sf::Sprite*> sprites;
    view::View::Type parentViewType;
};

}
#endif
