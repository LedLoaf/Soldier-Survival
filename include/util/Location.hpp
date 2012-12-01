#ifndef LOCATION_HPP
#define LOCATION_HPP

namespace util {

class Location {
public:
	enum Vector {
		TOP_LEFT, TOP_RIGT, TOP, DOWN_LEFT, DOWN_RIGHT, DOWN, LEFT, RIGHT
	};

	class Position {
	public:
		Position(int x, int y);
	private:
		int x;
		int y;
	};
};

} /* namespace util */
#endif
