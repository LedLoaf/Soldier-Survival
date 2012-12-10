#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <graphic/SFMLAbstractGraphicEngine.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>


#include <game/Application.hpp>

using namespace view;

namespace graphic {


void SFMLAbstractGraphicEngine::display() {
	updatePainters();

	//  display
	displayGraphicFromPainters();    
}


void SFMLAbstractGraphicEngine::updatePainters() {
	if (!isPaintingCurrentWindow())
		initWindowPainters(game::Application::getInstance().getContext()->getActiveWindow());

    for(std::vector<SFMLAbstractViewPainter*>::iterator it = painters.begin(); it != painters.end(); ++it) {
        (*it)->update();
    }
    
}


void SFMLAbstractGraphicEngine::initWindowPainters(Window* window) {
    renderWindow->Clear(sf::Color::Black);
	painters.clear();
    
    std::vector<view::View*> views = window->getViews();
    std::vector<view::View*> allViews;
    std::copy(views.begin(), views.end(), std::back_inserter(allViews));
     
    int size1 = allViews.size();

    int distance;
    
    std::vector<view::View*> subViews;
    
    
    for (int i = 0; i < views.size(); i++) {
        if (views[i]->hasViews()) {
            subViews = views[i]->getViews();
                for (int j = 0; j < subViews.size(); j++) 
                    allViews.push_back(subViews[j]);
        }
        
        distance = views[i]->getViews().size();
            
    }
    
    int size2 = allViews.size();
    view::View::Type type;
    
    for(std::vector<view::View*>::iterator it = allViews.begin(); it != allViews.end(); ++it) {
        type = (*it)->getType();
        painters.push_back(getPainterForView(*it, window->getType()));
    }
    
    currentWindowPainting = window;
}


bool SFMLAbstractGraphicEngine::isPaintingCurrentWindow() {
	if (currentWindowPainting == game::Application::getInstance().getContext()->getActiveWindow())
		return true;
	return false;
}


void SFMLAbstractGraphicEngine::displayGraphicFromPainters() {
    std::vector<sf::Drawable*> drawables;
  

    for(std::vector<SFMLAbstractViewPainter*>::iterator it = painters.begin(); it != painters.end(); ++it) {
        
        drawables = (*it)->getDrawables();        
        for(int i = 0; i < drawables.size(); i++)
            renderWindow->Draw(*drawables[i]);
        
    }
    
    renderWindow->Display();
}

void SFMLAbstractGraphicEngine::setRenderWindow(sf::RenderWindow* renderWindow) {
    this->renderWindow = renderWindow;
}



}
