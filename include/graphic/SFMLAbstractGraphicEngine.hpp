#ifndef SFML_GRAPHIC_ENGINE_H_
#define SFML_GRAPHIC_ENGINE_H_

#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

namespace graphic {

class SFMLAbstractGraphicEngine {

public:
    void setRenderWindow(sf::RenderWindow* renderWindow);
    
	void display();
	void updatePainters();
	void displayGraphicFromPainters();
	void initWindowPainters(view::Window* window);
	bool isPaintingCurrentWindow();
	virtual SFMLAbstractViewPainter* getPainterForView(view::View* view, view::View::Type parentViewType) = 0;

private:
    std::vector<SFMLAbstractViewPainter*> painters;
    view::Window* currentWindowPainting;
    sf::RenderWindow* renderWindow;

};

}

#endif

