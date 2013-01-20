#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

#include <vector>

namespace game {
    
class Equipment {
public: 
    class EquipmentItem {
    public:
        enum Type {
            KNIFE, SWORD, ENEMY_SWORD, AX, BOMB_A, 
        };
        
        EquipmentItem(Type type);
        
        Type getType() {
            return type;
        }
        
    protected:
        Type type;
    };
    
    Equipment();
    
    std::vector<EquipmentItem*>* getItems();
    void addItem(EquipmentItem* item);    
    
private:
    std::vector<EquipmentItem*>* items;
};
    
}

#endif