#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <sstream>
#include <string>

namespace util {
    
class Util {
public:
    enum Action {
        RUN_LEVEL_SELECTION, RUN_ABOUT, RUN_EXIT, RUN_GAME_PLAY
    };  
    
    std::string static toString(int integer) {
        std::ostringstream os;
        os << integer;

        return os.str();
    }
 
};

}
 /* namespace util */
#endif /* DEVICEMANAGER_HPP_ */
