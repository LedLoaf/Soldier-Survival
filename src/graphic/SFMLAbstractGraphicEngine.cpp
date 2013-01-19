#include <iostream>

#include <view/window/Window.hpp>
#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <graphic/SFMLAbstractGraphicEngine.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>


#include <game/Application.hpp>
#include <map>

using namespace view;

namespace graphic {


void SFMLAbstractGraphicEngine::display() {
	updatePainters();
	displayGraphicFromPainters();    
}


void SFMLAbstractGraphicEngine::updatePainters() {
    deleteUnusedWindowPainters(game::Application::getInstance().getContext()->getActiveWindow());
	updateWindowPainters(game::Application::getInstance().getContext()->getActiveWindow());
    
    if (game::Application::getInstance().getContext()->getActiveWindow()->hasSubWindow()) {
        deleteUnusedWindowPainters(game::Application::getInstance().getContext()->getActiveWindow()->getSubWindow());
        updateWindowPainters(game::Application::getInstance().getContext()->getActiveWindow()->getSubWindow());        
    }
    
    for (std::map<view::View*, graphic::SFMLAbstractViewPainter*>::const_iterator it = viewPainterMap.begin(); 
            it != viewPainterMap.end(); ++it) {
            renderWindow->Clear(sf::Color::Black);
        it->second->update();
    }
}

void SFMLAbstractGraphicEngine::deleteUnusedWindowPainters(Window* window) {
    if (window->hasUnusedViews()) {
        for (int i = 0; i < window->getUnusedViews().size(); i++) {
            View* unusedView = window->getUnusedViews()[i];
            for (std::map<view::View*, graphic::SFMLAbstractViewPainter*>::const_iterator it = viewPainterMap.begin(); 
                it != viewPainterMap.end(); ++it) {
                if (it->first == unusedView) {
                    std::cout << "SFMLAbstractGraphicEngine::deleteUnusedWindowPainters(): deleting unused painter" << std::endl;
                    viewPainterMap.erase(it->first);
                    
                    
                }
            }
        }
        window->clearUnusedViews();
//        renderWindow->Clear(sf::Color::Black);
    }
    
//
//    for (std::map<view::View*, graphic::SFMLAbstractViewPainter*>::iterator it = viewPainterMap.begin(); 
//            it != viewPainterMap.end(); ++it) {
//        if (it->first == NULL) {
//            delete it->second;
//            viewPainterMap.erase(it);
//            
//            renderWindow->Clear(sf::Color::Black);
//        }
//            
//    }
    
}

void SFMLAbstractGraphicEngine::addNewViewPainter(view::View* view, view::View::Type parentViewType) {
    if (viewPainterMap.find(view) == viewPainterMap.end()) {
        SFMLAbstractViewPainter* viewPainter = getPainterForView(view, parentViewType);
        viewPainterMap.insert(std::pair<view::View*, graphic::SFMLAbstractViewPainter*>(
            view, viewPainter));       
    }
}

void SFMLAbstractGraphicEngine::updateWindowPainters(Window* window) {
    for (int i = 0; i < window->getViews().size(); i++) {
        addNewViewPainter(window->getViews()[i], window->getViews()[i]->getType());
            
        for (int j = 0; j < window->getViews()[i]->getViews().size(); j++) {
            View* view = window->getViews()[i]->getViews()[j];
            if (view == NULL) {
                std::cout << "SFMLAbstractGraphicEngine::updateWindowPainters(): view is null";
            }
            addNewViewPainter(window->getViews()[i]->getViews()[j], window->getViews()[i]->getViews()[j]->getType());
        }
    }
}


void SFMLAbstractGraphicEngine::displayGraphicFromPainters() {
    for (std::map<view::View*, graphic::SFMLAbstractViewPainter*>::const_iterator it = viewPainterMap.begin(); 
            it != viewPainterMap.end(); ++it) 
        for (int i = 0; i < it->second->getDrawables().size(); i++)
            renderWindow->Draw(*it->second->getDrawables()[i]);
            

    renderWindow->Display();
}

void SFMLAbstractGraphicEngine::setRenderWindow(sf::RenderWindow* renderWindow) {
    this->renderWindow = renderWindow;
}



}
