
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


} /* namespace util */

