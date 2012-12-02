#ifndef GAME_PLAY_WINDOW_HPP_
#define GAME_PLAY_WINDOW_HPP_

#include <view/window/Window.hpp>
#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>

#include <util/Key.hpp>

namespace view {

class GamePlayWindow : public Window {

private:
	MapView* mapView;

public:
	GamePlayWindow(int xStart, int yStart, int xEnd, int yEnd, game::LevelDescription* levelDescription);
	void onEnterPressed();
	void onArrowPressed(util::Key::Arrow arrow);
	void setSubWindow(Window& window);
};

}

#endif