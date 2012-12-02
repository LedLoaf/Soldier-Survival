#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <graphic/SFMLAbstractGraphicEngine.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


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
	painters.clear();
    
    std::vector<view::View*> views = window->getViews();
    for(std::vector<view::View*>::iterator it = views.begin(); it != views.end(); ++it) {
        painters.push_back(getPainterForView(*it));
    }
}


bool SFMLAbstractGraphicEngine::isPaintingCurrentWindow() {
	if (currentWindowPainting == game::Application::getInstance().getContext()->getActiveWindow())
		return true;
	return false;
}


void SFMLAbstractGraphicEngine::displayGraphicFromPainters() {
    std::vector<sf::Sprite*> sprites;
    
    for(std::vector<SFMLAbstractViewPainter*>::iterator it = painters.begin(); it != painters.end(); ++it) {
        
        sprites = (*it)->getSprites();
        for(std::vector<sf::Sprite*>::iterator spriteIt = sprites.begin(); spriteIt != sprites.end(); ++spriteIt) {
            renderWindow->Draw(**spriteIt);
        }    
    }
}

void SFMLAbstractGraphicEngine::setRenderWindow(sf::RenderWindow* renderWindow) {
    this->renderWindow = renderWindow;
}



}
