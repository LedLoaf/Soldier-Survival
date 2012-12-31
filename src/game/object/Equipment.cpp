
#include "game/object/Equipment.hpp"



namespace game {
    
void Equipment::addItem(EquipmentItem* item) {
    items->push_back(item);
}  
    
    
std::vector<Equipment::EquipmentItem*>* Equipment::getItems() {
    return items;
}
    

}