#ifndef WAR_VIEW_MODEL_HPP_
#define WAR_VIEW_MODEL_HPP_
#include <vector>
#include <iostream>

#include <util/Util.hpp>
#include <util/Location.hpp>
#include <view/model/ViewModel.hpp>

namespace game {
    class Player;
    class Enemy;
}

namespace view {

class WarViewModel : public ViewModel {
public:
    void setPlayer(game::Player* player);
    void setEnemy(game::Enemy* enemy);
    
    int getEnemyHealth();
    util::Location::Position getEnemyPosition();
    


private:
    game::Player* player;
    game::Enemy* enemy;
};

} /* namespace view */
#endif 
