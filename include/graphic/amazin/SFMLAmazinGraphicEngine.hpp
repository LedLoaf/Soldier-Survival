#ifndef SFML_AMAZIN_GRAPHIC_ENGINE_H_
#define SFML_AMAZIN_GRAPHIC_ENGINE_H_

#include <view/window/Window.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <graphic/SFMLAbstractGraphicEngine.hpp>


namespace graphic {
namespace amazin {

class SFMLAmazinGraphicEngine : public SFMLAbstractGraphicEngine {

public:
	virtual ~SFMLAmazinGraphicEngine();

	void display();
	void updatePainters();
	void displayGraphicFromPainters();
	void initWindowPainters(view::Window& window);
	bool isPaintingCurrentWindow();
	virtual SFMLAbstractViewPainter* getPainterForView(view::View* view, view::View::Type parentViewType);

private:


};

}
}

#endif

