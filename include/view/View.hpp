/*
 * View.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef VIEW_HPP_
#define VIEW_HPP_

namespace view {

class View {
public:
	View(int x, int y, int width, int height);
	virtual ~View();

protected:
	int x;
	int y;
	int width;
	int height;
};

} /* namespace graphic */
#endif /* VIEW_HPP_ */
