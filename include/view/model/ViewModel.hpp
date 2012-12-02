#ifndef VIEW_MODEL_HPP
#define VIEW_MODEL_HPP

#include <util/Location.hpp>


namespace view {

class ViewModel {
public:
    util::Location::Position* getViewStartPosition();
    util::Location::Position* getViewEndPosition();
    
    void setViewPosition(util::Location::Position* startPosition, util::Location::Position* endPosition);
    
private:
    util::Location::Position* startPosition;
    util::Location::Position* endPosition;
};

}
#endif
