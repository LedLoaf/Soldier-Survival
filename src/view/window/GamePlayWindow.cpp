class GamePlayWindow {
private:
	HUDHandler* hudHandler;
	MapHandler* mapHandler;
	Player* player;

public:
	GamePlayWindow(LevelDescription& levelDescription) {

		this.HUDView = new HUDView(levelDescription);
		this.mapView = new MapView(levelDescription);
		this.miniMapWindow = new MiniMapWindow();

		this.player = mapHandler->getPlayer();
	}

	void onEnterPressed() {
	}

	// strzalki sa do poruszania przeciwnikiem
	// czyli przekazuje to zdarzenie dalej do MapWindow
	void onArrowPressed(arrow) {
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




}