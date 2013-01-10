#ifndef LEVEL_DESCRIPTION_H_
#define LEVEL_DESCRIPTION_H_

#include <game/object/Equipment.hpp>

namespace game {

class LevelDescription {
public:
    LevelDescription(int width, int height, float enemyDen, int enemyMin, 
            int enemyMax, bool enemyKnife, bool enemyGun, bool enemyRifle, bool playerKnife, bool playerGun, bool playerRifle) {
        mapWidth = width;
        mapHeight = height;
        
        enemyDensity = enemyDen;
        enemyPlacesMin = enemyMin;
        enemyPlacesMax = enemyMax;
        
        enemyTypeKnife = enemyKnife;
        enemyTypeGun = enemyGun;
        enemyTypeRifle = enemyRifle;
        
        playerHealth = 100;
        
        playerEquipment = new Equipment();
        
        if (playerKnife) playerEquipment->addItem(new Equipment::EquipmentItem(Equipment::EquipmentItem::KNIFE));
        if (playerGun) playerEquipment->addItem(new Equipment::EquipmentItem(Equipment::EquipmentItem::GUN));
        if (playerRifle) playerEquipment->addItem(new Equipment::EquipmentItem(Equipment::EquipmentItem::RIFLE));
    }
    
    void setPlayerEquipment(Equipment* equipment) {
        playerEquipment = equipment;
    }
    
    Equipment* getPlayerEquipment() {
        return playerEquipment;
    }
    
    void setPlayerHealth(int health) {
        this->playerHealth = health;
    }
    
    int getPlayerHealth() {
        return playerHealth;
    }
    
    int getMapWidth() {
        return mapWidth;
    }
    
    int getMapHeight() {
        return mapHeight;
    }
    
    int getSizeHeight() {
        return mapHeight;
    }
    void setSizeHeight(int mapHeight) {
        this->mapHeight = mapHeight;
    }
    
    float getEnemyDensity() {
        return enemyDensity;
    }
    void setEnemyDensity(float enemyDensity) {
        this->enemyDensity = enemyDensity;
    }
    
    int getEnemyPlacesMin() {
        return enemyPlacesMin;
    }
    void setEnemyPlacesMin(int enemyPlacesMin) {
        this->enemyPlacesMin = enemyPlacesMin;
    }
    
    int getEnemyPlacesMax() {
        return enemyPlacesMax;
    }
    void setEnemyPlacesMax(int enemyPlacesMax) {
        this->enemyPlacesMax = enemyPlacesMax;
    }
    
    bool getEnemyTypeKnife() {
        return enemyTypeKnife;
    }
    void setEnemyTypeKnife(bool enemyTypeKnife) {
        this->enemyTypeKnife = enemyTypeKnife;
    }
    
    bool getEnemyTypeGun() {
        return enemyTypeGun;
    }
    void setEnemyTypeGun(bool enemyTypeGun) {
        this->enemyTypeGun = enemyTypeGun;
    }
/*
    bool getEnemyTypeRifle() {
        return enemyTypeRifle;
    }
    void setEnemyTypeRifle(bool enemyTypeRifle) {
        this->enemyTypeRifle = enemyTypeRifle;
    }
    
    bool getPlayerWeaponKnife() {
        return playerWeaponKnife;
    }
    void setPlayerWeaponKnife(bool playerWeaponKnife) {
        this->playerWeaponKnife = playerWeaponKnife;
    }
    
    bool getPlayerWeaponGun() {
        return playerWeaponGun;
    }
    void setPlayerWeaponGun(bool playerWeaponGun) {
        this->playerWeaponGun = playerWeaponGun;
    }
    
    bool getPlayerWeaponRifle() {
        return playerWeaponRifle;
    }
    void setPlayerWeaponRifle(bool playerWeaponRifle) {
        this->playerWeaponRifle = playerWeaponRifle;
    }
*/
private:
    int mapWidth;
    int mapHeight;
    
    float enemyDensity; // 0.2
    int enemyPlacesMin; // 9
    int enemyPlacesMax; // 20
    
    bool enemyTypeKnife;
    bool enemyTypeGun;
    bool enemyTypeRifle;
    
    /*
    bool playerWeaponKnife;
    bool playerWeaponGun;
    bool playerWeaponRifle;
    */
    
    int playerHealth;
    Equipment* playerEquipment;
};

}

#endif

