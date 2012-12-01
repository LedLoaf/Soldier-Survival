#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>

namespace graphic {


void SFMLAbstractGraphicEngine::display() {
	updatePainters();

	//  display
	displayGraphicFromPainters();
}


void SFMLAbstractGraphicEngine::updatePainters() {
	if (!isPaintingCurrentWindow())
		initWindowPainters(game::Application::getContext().getActiveWindow());

	for (Painter painter : windowPainters) {
		painter.update();
	}
}


void SFMLAbstractGraphicEngine::initWindowPainters(Window& window) {
	painters.clear();

	for (View view : window.getViews()) {
		painters.add(getPainterForView(view))
	}
}


bool SFMLAbstractGraphicEngine::isPaintingCurrentWindow() {
	if (currentWindowPainting == Application.getContext().getActiveWindow())
		return true;
	return false;
}


void SFMLAbstractGraphicEngine::displayGraphicFromPainters() {
	for (Painter p : painters) 
		for (Sprite sprite : p.getSprites())
			smflWindow->Draw(sprite);
}


}
