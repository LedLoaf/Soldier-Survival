#ifndef WAR_VIEW_HPP_
#define WAR_VIEW_HPP_

#include <view/View.hpp>

#include "model/WarViewModel.hpp"


namespace view {
    
class WarViewModel;
class ViewModel;

class WarView : public View {
public:
    WarView(view::WarViewModel* warViewModel);
    
    virtual Type getType();
    view::WarViewModel* getModel();
     
private:
    WarViewModel* warViewModel;
};

}

#endif
