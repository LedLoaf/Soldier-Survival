#include <view/SelectionView.hpp>
#include <view/HUDView.hpp>
#include <view/ImageView.hpp>
#include <util/Location.hpp>

#include <game/object/weapon/Weapon.hpp>

#include "game/object/Equipment.hpp"


namespace view {

HUDView::HUDView(int xStart, int yStart, int xEnd, int yEnd, HUDViewModel* hudViewModel) : View(xStart, yStart, xEnd, yEnd) {   
    this->hudViewModel = hudViewModel;
    this->hudViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));

    weaponsSelectionView = new SelectionView(100, 0, 300, 100, view::SelectionViewModel::WEAPONS);
    
    
    game::Equipment* playerEquipment = this->hudViewModel->getPlayerEquipment();
    
    std::vector<game::Equipment::EquipmentItem*> equipmentItems = playerEquipment->getItems();
    for (int i = 0; i < equipmentItems->size(); i++) {
        if (game::Weapon::isWeapon(equipmentItems[i])) 
            weaponsSelectionView->addElement(new SelectionViewModel::WeaponSelectableElement(
                    dynamic_cast<game::Weapon*>equipmentItems[i]));    
            
    }
        
    
    addView(weaponsSelectionView);
}    

HUDViewModel* HUDView::getModel() {
    return this->hudViewModel;
}

View::Type HUDView::getType() {
    return view::View::HUD_VIEW;
}


SelectionView* HUDView::getWeaponSelectionView() {
    return this->weaponsSelectionView;
};

void HUDView::pause() {
        
}

void HUDView::resume() {
    
}

}