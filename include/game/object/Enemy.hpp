#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <game/object/Character.hpp>
#include <game/object/weapon/Weapon.hpp>


namespace game {
    
class Enemy : public Character {
public:

    void setWeapon(Weapon* weapon);
    Weapon* gettWeapon();
    
    virtual void startMoving();
    
    class MovementAI {
    public:
        MovementAI() {
            mapView = ((view::GamePlayWindow) Application.getContext()->getActiveWindow())->getMapView();
        }
        virtual void move() = 0;
    protected:
        view::MapView* mapView;
    };
    
    class EnemyMovementAI : public MovementAI {
    public:
        EnemyMovementAI(Enemy* enemy)  : MovementAI() {
            this->enemy = enemy;
        }
        
        virtual void move() {
            // na danej podstawie okresl kierunek - direction
            util::Location::Vector direction = util::Location::DOWN;
            if (mapView->canMoveCharacter(enemy, direction)) 
                mapView->moveCharacter(enemy, direction); 
            else {
                // okresl kierunek na nowo
            }
                
        }
        
    protected:
        Enemy* enemy;
    };
    
private:
    Weapon* weapon;
    
};
    
}

#endif