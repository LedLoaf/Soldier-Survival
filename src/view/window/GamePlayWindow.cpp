#include <view/window/GamePlayWindow.hpp>
#include <game/Application.hpp>

namespace view {

GamePlayWindow::GamePlayWindow(int xStart, int yStart, int xEnd, int yEnd, game::LevelDescription* levelDescription) : Window(xStart, yStart, xEnd, yEnd) {

//		this.HUDView = new HUDView(levelDescription);

    this->mapView = new MapView(0, 200, game::Application::getInstance().getDeviceManager()->getScreenWidth(), 
            game::Application::getInstance().getDeviceManager()->getScreenHeight() - 200);
    this->mapView->generateLevel(levelDescription);
    
    
//		this.miniMapWindow = new MiniMapWindow();

//		this.player = mapHandler->getPlayer();
}

void GamePlayWindow::onEnterPressed() {
}


void GamePlayWindow::onArrowPressed(util::Key::Arrow arrow) {
    
    
//	if (hasSubWindow()) {
//		subWindow->onArrowPressed(arrow);
//
//		return;
//	}
//
//
//	if (mapView->canMoveCharacter(arrow))
//		mapView->moveCharacter(arrow);
}

}
