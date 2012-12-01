#ifndef GAME_PLAY_WINDOW_HPP_
#define GAME_PLAY_WINDOW_HPP_

#include <view/window/Window.hpp>
#include <view/MapView.hpp>
#include <game/object/LevelDescription.hpp>

#include <util/Key.hpp>

namespace view {

class GamePlayWindow : Window {

private:
	MapView& mapView;

public:
	GamePlayWindow(game::LevelDescription& levelDescription) {

//		this.HUDView = new HUDView(levelDescription);
		this->mapView = new MapView(levelDescription);
//		this.miniMapWindow = new MiniMapWindow();

//		this.player = mapHandler->getPlayer();
	}

	void onEnterPressed() {
	}

	// strzalki sa do poruszania przeciwnikiem
	// czyli przekazuje to zdarzenie dalej do MapWindow
	void onArrowPressed(util::Key::Arrow arrow) {
		if (hasSubWindow()) {
			subWindow.onArrowPressed(arrow);

			return;
		}


		if (mapView.canMoveCharacter(vector))
			mapView.moveCharacter(vector);
	}

	void setSubWindow(Window& window) {
		subWindow = window;
	}
};

}
