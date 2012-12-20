
#include "util/Location.hpp"


namespace util {

Location::Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

int Location::Position::getX() {
    return x;
}

int Location::Position::getY() {
    return y;
}


Location::Position Location::Position::operator+(const Location::Vector vector) {
    Location::Position newPosition(this);
 
    switch (vector) {
        case Location::Vector::UP :
            newPosition.setY(this->getY() + 1);
            break;
        case Location::Vector::RIGHT :
            newPosition.setX(this->getX() + 1);
            break; 
        case Location::Vector::DOWN :
            newPosition.setY(this->getY() - 1);
            break;
        case Location::Vector::LEFT :
            newPosition.setX(this->getX() - 1);
            break;             
    }
    
    return newPosition;
}

} /* namespace util */

