#ifndef HUD_VIEW_HPP_
#define HUD_VIEW_HPP_

#include <view/View.hpp>
#include <view/model/HUDViewModel.hpp>
#include <iostream>
#include <list>

#include "SelectionView.hpp"


namespace view {

class HUDView : public View {
public:
    HUDView(int xStart, int yStart, int xEnd, int yEnd);
    HUDViewModel* getModel();
    
    virtual View::Type getType();
    
    virtual void pause();
    virtual void resume();
    
    SelectionView* getWeaponSelectionView();

private:
	HUDViewModel* hudViewModel;
    SelectionView* weaponsSelectionView;
	
};

}
#endif
