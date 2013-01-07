
#include "game/object/Equipment.hpp"



namespace game {
    
Equipment::Equipment() {
    this->items = new std::vector<Equipment::EquipmentItem*>();
} 

Equipment::EquipmentItem::EquipmentItem(Type type) {
    this->type = type;
}    
void Equipment::addItem(EquipmentItem* item) {
    items->push_back(item);
}  
    
    
std::vector<Equipment::EquipmentItem*>* Equipment::getItems() {
    return items;
}
    

}