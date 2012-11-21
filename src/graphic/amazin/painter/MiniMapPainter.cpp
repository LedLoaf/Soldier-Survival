
void paint() {
	miniMapWindow = (MiniMapWindow) gameEngine->getContext()->getActiveWindow()->getMiniMapWindow();

	if (miniMapWindow != NULL) {
		miniMapWindowModel = miniMapWindow.getModel();

		// kozystajac z modelu opisujacego miniMape tworzy odpowiednie sprite
	}
	
}