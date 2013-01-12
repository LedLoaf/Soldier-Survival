#ifndef LOCATION_HPP_
#define LOCATION_HPP_

namespace util {

class Location {
public:
	enum Vector {
		UP_LEFT, UP_RIGHT, UP, DOWN_LEFT, DOWN_RIGHT, DOWN, LEFT, RIGHT, NOWHERE
	};

  
    Vector static getOppositeVector(Vector vector) {
        if (vector == LEFT)
            return RIGHT;
        if (vector == UP_LEFT)
            return DOWN_RIGHT;
        if (vector == UP)
            return DOWN;
        if (vector == UP)
            return DOWN;
        if (vector == UP_RIGHT)
            return DOWN_LEFT;
        if (vector == RIGHT)
            return DOWN; 
        if (vector == DOWN_RIGHT)
            return UP_LEFT;
        if (vector == DOWN)
            return UP;
        if (vector == DOWN_LEFT)
            return UP_RIGHT;         
    }   
    
    Vector static getVectorSum(Vector firstVector, Vector secondVector) {
        if (firstVector == secondVector)
            return firstVector;
        if (firstVector == NOWHERE && secondVector != NOWHERE) 
            return secondVector;
        if (secondVector == NOWHERE && firstVector != NOWHERE) 
            return firstVector;        
        if ((firstVector == UP && secondVector == RIGHT) || (secondVector == UP && firstVector == RIGHT))
            return UP_RIGHT;   
        if ((firstVector == RIGHT && secondVector == DOWN) || (secondVector == RIGHT && firstVector == DOWN))
            return DOWN_RIGHT;
        if ((firstVector == UP && secondVector == RIGHT) || (secondVector == UP && firstVector == RIGHT)) 
            return UP_RIGHT;   
        if ((firstVector == RIGHT && secondVector == DOWN) || (secondVector == RIGHT && firstVector == DOWN)) 
            return DOWN_RIGHT;    
        if ((firstVector == LEFT && secondVector == DOWN) || (secondVector == LEFT && firstVector == DOWN)) 
            return DOWN_LEFT;      
        if ((firstVector == UP && secondVector == LEFT) || (secondVector == UP && firstVector == LEFT)) 
            return UP_LEFT;    
        
        return NOWHERE;
    }
    
    
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
