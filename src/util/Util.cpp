#include <util/Util.hpp> 

namespace util {

std::string toString(int integer) {
    std::ostringstream os;
    os << integer;

    return os.str();
}

}