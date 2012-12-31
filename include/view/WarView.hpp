#ifndef WAR_VIEW_HPP_
#define WAR_VIEW_HPP_

#include <view/View.hpp>


namespace view {

class WarView : public View {
public:
    WarView(int xStart, int yStart, int xEnd, int yEnd);
    
    virtual Type getType();
};

}

#endif
