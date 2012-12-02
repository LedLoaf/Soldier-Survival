#ifndef VIEW_MODEL_HPP
#define VIEW_MODEL_HPP

#include <util/Location.hpp>


namespace view {

class ViewModel {
public:
    util::Location::Position getViewPosition();
    void setViewPosition(util::Location::Position position);
};

}
#endif
