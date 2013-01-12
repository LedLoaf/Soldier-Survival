
#include <util/Location.hpp>

namespace util {
    
Location::Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

int Location::Position::getX() const {
    return x;
}

int Location::Position::getY() const {
    return y;
}

void Location::Position::setX(int x) {
    this->x = x;
}

void Location::Position::setY(int y) {
    this->y = y;
}

Location::Position Location::Position::operator+(const Location::Vector vector) {
    Location::Position newPosition(this->getX(), this->getY());
 
    switch (vector) {
        case Location::LEFT :
            newPosition.setX(this->getX() - 1);
            break;            
        case Location::UP_LEFT :
            newPosition.setX(this->getX() - 1);
            newPosition.setY(this->getY() - 1);
            break;        
        case Location::UP :
            newPosition.setY(this->getY() - 1);
            break;
        case Location::UP_RIGHT :
            newPosition.setX(this->getX() + 1);
            newPosition.setY(this->getY() - 1);
            break;             
        case Location::RIGHT :
            newPosition.setX(this->getX() + 1);
            break; 
        case Location::DOWN_RIGHT :
            newPosition.setX(this->getX() + 1);
            newPosition.setY(this->getY() + 1);
            break;             
        case Location::DOWN :
            newPosition.setY(this->getY() + 1);
            break;
        case Location::DOWN_LEFT :
            newPosition.setX(this->getX() - 1);
            newPosition.setY(this->getY() + 1);
            break;            
    }
    
    return newPosition;
}

} /* namespace util */

