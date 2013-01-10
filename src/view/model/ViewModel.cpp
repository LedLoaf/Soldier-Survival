#include <util/Location.hpp>
#include <view/model/ViewModel.hpp>


namespace view {

util::Location::Position* ViewModel::getViewStartPosition() {
    return startPosition;
}

util::Location::Position* ViewModel::getViewEndPosition() {
    return endPosition;
}

void ViewModel::setViewPosition(util::Location::Position* startPosition, util::Location::Position* endPosition) {
    this->startPosition = startPosition;
    this->endPosition = endPosition;
}
    

}