#ifndef LOCATION_HPP
#define LOCATION_HPP

namespace util {

class Location {
public:
	enum Vector {
		UP_LEFT, UP_RIGT, UP, DOWN_LEFT, DOWN_RIGHT, DOWN, LEFT, RIGHT
	};

	class Position {
	public:
		Position(int x, int y);
        int getX();
        int getY();
        
        void setX(int x);
        void setY(int y);
        
        Location::Position Location::Position::operator+(const Location::Vector vector);
	private:
		int x;
		int y;
	};
};

} /* namespace util */
#endif
