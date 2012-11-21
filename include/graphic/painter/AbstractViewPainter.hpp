/*
 * ViewPainter.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef VIEW_PAINTER_HPP_
#define VIEW_PAINTER_HPP_

namespace view {

class AbstractViewPainter {
public:
	AbstractViewPainter();
	virtual ~AbstractViewPainter();

	void init() = 0;
	void update() = 0;

	List<Sprite> getSprites();

private:
	List<Sprite> sprites;
};

} /* namespace view */
#endif
