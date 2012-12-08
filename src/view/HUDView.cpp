#include <view/SelectionView.hpp>
#include <view/HUDView.hpp>
#include <util/Location.hpp>

#include <game/object/weapon/Weapon.hpp>


namespace view {

HUDView::HUDView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {   
    hudViewModel = new HUDViewModel();
    hudViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));

    
    SelectionView* weaponsSelectionView = new SelectionView(100, 0, 300, 100, view::SelectionViewModel::WEAPONS);
    weaponsSelectionView->addElement(new SelectionViewModel::WeaponSelectableElement(new game::Weapon(game::Weapon::KNIFE)));    
    
    
    addView(weaponsSelectionView);
}    

void HUDView::setHUDModel(HUDViewModel* hudViewModel) { 
    this->hudViewModel = hudViewModel;
}

HUDViewModel* HUDView::getModel() {
    return this->hudViewModel;
}

View::Type HUDView::getType() {
    return view::View::HUD_VIEW;
}

}