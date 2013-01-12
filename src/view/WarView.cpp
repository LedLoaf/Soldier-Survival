#include <view/View.hpp>
#include <view/WarView.hpp>

#include "view/model/WarViewModel.hpp"

namespace view {

WarView::WarView(view::WarViewModel* warViewModel) : View(-1, -1, -1, -1) {
    this->warViewModel = warViewModel;
}
    
    
View::Type WarView::getType() {
    return View::WAR_VIEW;
}

view::WarViewModel* WarView::getModel() {
    return warViewModel;
}

}
