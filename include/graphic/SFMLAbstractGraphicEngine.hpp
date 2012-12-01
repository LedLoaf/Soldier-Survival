#ifndef SFML_GRAPHIC_ENGINE_H_
#define SFML_GRAPHIC_ENGINE_H_

#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>

namespace graphic {

class SFMLAbstractGraphicEngine {

public:
	void display();
	void updatePainters();
	void displayGraphicFromPainters();
	void initWindowPainters(view::Window& window);
	bool isPaintingCurrentWindow();
	void displayGraphicFromPainters();
	virtual SFMLAbstractViewPainter& getPainterForView(const view::View& view) = 0;

private:


};

}

#endif

