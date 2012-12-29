#ifndef GAME_PLAY_WINDOW_HPP_
#define GAME_PLAY_WINDOW_HPP_

#include <view/window/Window.hpp>
#include <view/MapView.hpp>
#include <view/HUDView.hpp>
#include <view/MiniMapView.hpp>
#include <game/object/LevelDescription.hpp>
#include <game/LevelGenerator.hpp>

#include <util/Key.hpp>
#include <game/WarManager.hpp>

namespace view {

class GamePlayWindow : public Window {

private:
    HUDView* hudView;
	MapView* mapView;
    MiniMapView* miniMapView;
    game::LevelDescription* levelDescription;
    game::LevelGenerator* levelGenerator;
    game::WarManager* warManager;

public:
	GamePlayWindow(game::LevelDescription* levelDescription);
	void initUI();
        
	virtual void onEnterPressed();
	virtual void onArrowPressed(util::Key::Arrow arrow);
    virtual void onEscPressed();
    
	virtual Type getType();
    
    virtual void pause();
    virtual void resume();
    
    MapView* getMapView();
    
};

}

#endif