#include <view/View.hpp>
#include <view/WarView.hpp>


namespace view {

WarView::WarView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {
    
}
    
    
View::Type WarView::getType() {
    return View::WAR_VIEW;
}

}
