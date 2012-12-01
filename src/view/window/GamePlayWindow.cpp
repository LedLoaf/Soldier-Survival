namespace view {


GamePlayWindow::GamePlayWindow(game::LevelDescription& levelDescription) {

//		this.HUDView = new HUDView(levelDescription);
	this->mapView = new MapView(levelDescription);
//		this.miniMapWindow = new MiniMapWindow();

//		this.player = mapHandler->getPlayer();
}

void GamePlayWindow::onEnterPressed() {
}

// strzalki sa do poruszania przeciwnikiem
// czyli przekazuje to zdarzenie dalej do MapWindow
void GamePlayWindow::onArrowPressed(util::Key::Arrow arrow) {
	if (hasSubWindow()) {
		subWindow.onArrowPressed(arrow);

		return;
	}


	if (mapView.canMoveCharacter(vector))
		mapView.moveCharacter(vector);
}


}
