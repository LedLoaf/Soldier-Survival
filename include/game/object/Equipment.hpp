#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

#include <vector>

namespace game {
    
class Equipment {
public:
    
    std::vector<EquipmentItem>* getItems();
    void addItem(EquipmentItem* item);

    
    class EquipmentItem {
    public:
        enum Type {
            KNIFE, GUN, RIFLE, AMMO
        };
        
        virtual Type getType() = 0;
    };
    
private:
    std::vector<EquipmentItem>* items;
};
    
}

#endif