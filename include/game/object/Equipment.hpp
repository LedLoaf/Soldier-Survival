#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

#include <vector>

namespace game {
    
class Equipment {
public: 
    class EquipmentItem {
    public:
        enum Type {
            KNIFE, GUN, RIFLE, AMMO
        };
        
        Type getType() {
            return type;
        }
        
    private:
        Type type;
    };
    
    std::vector<EquipmentItem*>* getItems();
    void addItem(EquipmentItem* item);    
    
private:
    std::vector<EquipmentItem*>* items;
};
    
}

#endif