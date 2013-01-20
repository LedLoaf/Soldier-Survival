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
    game::LevelDescription* levelDescription;
    game::LevelGenerator* levelGenerator;
    bool isGameOver;

public:
	GamePlayWindow(game::LevelDescription* levelDescription);
    ~GamePlayWindow();
	void initUI();
    
    void gameOver();
        
	virtual void onEnterPressed();
	virtual void onArrowPressed(util::Location::Vector vector);
    virtual void onEscPressed();
    virtual void onCharacterPressed(char c);
    virtual void onSpacePressed();
    
	virtual Type getType();
    
    virtual void pause();
    virtual void resume();
    
    MapView* getMapView();
    
};

}

#endif