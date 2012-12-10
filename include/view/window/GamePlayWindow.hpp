#ifndef GAME_PLAY_WINDOW_HPP_
#define GAME_PLAY_WINDOW_HPP_

#include <view/window/Window.hpp>
#include <view/MapView.hpp>
#include <view/HUDView.hpp>
#include <game/object/LevelDescription.hpp>

#include <util/Key.hpp>

namespace view {

class GamePlayWindow : public Window {

private:
    HUDView* hudView;
	MapView* mapView;
    game::LevelDescription* levelDescription;
    game::LevelGenerator* levelGenerator;

public:
	GamePlayWindow(game::LevelDescription* levelDescription);
	void initUI();
        
	virtual void onEnterPressed();
	virtual void onArrowPressed(util::Key::Arrow arrow);
    virtual void onEscPressed();
    
	virtual Type getType();
    
};

}

#endif