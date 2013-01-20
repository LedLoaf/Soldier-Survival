#include <view/SelectionView.hpp>
#include <view/HUDView.hpp>
#include <view/ImageView.hpp>
#include <view/TextView.hpp>
#include <util/Location.hpp>

#include <game/object/weapon/Weapon.hpp>

#include "game/object/Equipment.hpp"


namespace view {

HUDView::HUDView(int xStart, int yStart, int xEnd, int yEnd, HUDViewModel* hudViewModel) : View(xStart, yStart, xEnd, yEnd) {   
    this->hudViewModel = hudViewModel;
    this->hudViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));

    addView(new TextView(120, 0, 300, 40, "Hand weapons", TextView::MIDDLE));

    weaponsSelectionView = new SelectionView(120, 30, 300, yEnd, view::SelectionViewModel::WEAPONS);
    
    
    game::Equipment* playerEquipment = this->hudViewModel->getPlayerEquipment();
    
    std::vector<game::Equipment::EquipmentItem*>* equipmentItems = playerEquipment->getItems();
    for (int i = 0; i < equipmentItems->size(); i++) {
        if (game::Weapon::isWeapon(equipmentItems->at(i)))
            weaponsSelectionView->addElement(new SelectionViewModel::WeaponSelectableElement(
                    static_cast<game::Weapon*>(equipmentItems->at(i))));    
            
    }
    weaponsSelectionView->selectElement(0);
    
    addView(weaponsSelectionView);
}    

HUDViewModel* HUDView::getModel() {
    return this->hudViewModel;
}

View::Type HUDView::getType() {
    return view::View::HUD_VIEW;
}

void HUDView::switchToPreviousWeapon() {
    if (weaponsSelectionView->hasPreviousElement()) {
        weaponsSelectionView->selectPreviousElement();
    }
}

void HUDView::switchToNextWeapon() {
    if (weaponsSelectionView->hasNextElement()) {
        weaponsSelectionView->selectNextElement();
        hudViewModel->setCurrentWeaponForPlayer(
            dynamic_cast<SelectionViewModel::WeaponSelectableElement*>(weaponsSelectionView->getSelectedElement())->getWeapon());
    }    
}

SelectionView* HUDView::getWeaponSelectionView() {
    if (weaponsSelectionView->hasNextElement()) {
        weaponsSelectionView->selectNextElement();    
        hudViewModel->setCurrentWeaponForPlayer(
            dynamic_cast<SelectionViewModel::WeaponSelectableElement*>(weaponsSelectionView->getSelectedElement())->getWeapon());        
    }
};

void HUDView::pause() {
        
}

void HUDView::resume() {
    
}

}