#ifndef HUD_VIEW_HPP_
#define HUD_VIEW_HPP_

#include <view/View.hpp>
#include <view/model/HUDViewModel.hpp>
#include <iostream>
#include <list>


namespace view {

class HUDView : public View {
public:
    HUDView(int xStart, int yStart, int xEnd, int yEnd);
    void setHUDModel(HUDViewModel* hudViewModel);
    HUDViewModel* getModel();
    
    virtual View::Type getType();

private:
	HUDViewModel* hudViewModel;
    
	
};

}
#endif
