
#include <util/Location.hpp>

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
    Location::Position newPosition(this->getX(), this->getY());
 
    switch (vector) {
        case Location::UP :
            newPosition.setY(this->getY() + 1);
            break;
        case Location::RIGHT :
            newPosition.setX(this->getX() + 1);
            break; 
        case Location::DOWN :
            newPosition.setY(this->getY() - 1);
            break;
        case Location::LEFT :
            newPosition.setX(this->getX() - 1);
            break;             
    }
    
    return newPosition;
}

} /* namespace util */

