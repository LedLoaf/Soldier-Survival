#ifndef LOCATION_HPP_
#define LOCATION_HPP_

namespace util {

class Location {
public:
	enum Vector {
		UP_LEFT, UP_RIGT, UP, DOWN_LEFT, DOWN_RIGHT, DOWN, LEFT, RIGHT, NOWHERE
	};

	class Position {
	public:
		Position(int x, int y);
        int getX() const;
        int getY() const;
        
        void setX(int x);
        void setY(int y);
        
        Position operator+(const Location::Vector vector);
        
	private:
		int x;
		int y;
	};
};

} /* namespace util */
#endif
