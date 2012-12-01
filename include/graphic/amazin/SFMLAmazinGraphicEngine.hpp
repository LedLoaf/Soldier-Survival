#ifndef SFML_AMAZIN_GRAPHIC_ENGINE_H_
#define SFML_AMAZIN_GRAPHIC_ENGINE_H_

#include <view/window/Window.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace graphic {
namespace amazin {

class SFMLAmazinGraphicEngine : SFMLAbstractGraphicEngine {

public:
	virtual ~SFMLAmazinGraphicEngine();

	void display();
	void updatePainters();
	void displayGraphicFromPainters();
	void initWindowPainters(view::Window& window);
	bool isPaintingCurrentWindow();
	void displayGraphicFromPainters();
	virtual SFMLAbstractViewPainter& getPainterForView(const view::View& view);

private:


};

}
}

#endif

