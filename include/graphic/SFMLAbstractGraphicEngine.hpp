#ifndef SFML_GRAPHIC_ENGINE_H_
#define SFML_GRAPHIC_ENGINE_H_

#include <map>

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

private:
	void displayGraphicFromPainters();
	void updateWindowPainters(view::Window* window);
	virtual SFMLAbstractViewPainter* getPainterForView(view::View* view, view::View::Type parentViewType) = 0;
    
    void addNewViewPainter(view::View* view, view::View::Type parentViewType);
    void deleteUnusedWindowPainters();
    
    std::map<view::View*, graphic::SFMLAbstractViewPainter*> viewPainterMap;    
    std::vector<SFMLAbstractViewPainter*> painters;
    sf::RenderWindow* renderWindow;

};

}

#endif

