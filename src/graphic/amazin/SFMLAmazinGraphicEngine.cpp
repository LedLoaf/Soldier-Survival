
#include <graphic/amazin/SFMLAmazinGraphicEngine.hpp>
#include <view/View.hpp>
#include <view/window/Window.hpp>
#include <view/SelectionView.hpp>
#include <view/ImageView.hpp>
#include <view/HUDView.hpp>
#include <view/MiniMapView.hpp>
#include <view/MapView.hpp>
//#include <view/TextView.hpp>

#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <graphic/amazin/painter/ImageViewPainter.hpp> 
#include <graphic/amazin/painter/HUDViewPainter.hpp>
#include <graphic/amazin/painter/MiniMapViewPainter.hpp>


#include "graphic/amazin/painter/MapViewPainter.hpp"
#include "graphic/amazin/painter/WarViewPainter.hpp"
//#include <graphic/amazin/painter/TextViewPainter.hpp>


namespace graphic {
namespace amazin {


SFMLAbstractViewPainter* SFMLAmazinGraphicEngine::getPainterForView(view::View* view, view::View::Type parentViewType) {
	switch (view->getType()) {
        case view::View::SELECTION_VIEW :
            return new graphic::amazin::SelectionViewPainter(dynamic_cast<view::SelectionView*>(view)->getModel());
        case view::View::IMAGE_VIEW :
            return new graphic::amazin::ImageViewPainter(dynamic_cast<view::ImageView*>(view)->getModel(), parentViewType);
//        case view::View::TEXT_VIEW :
//            return new graphic::amazin::TextViewPainter(dynamic_cast<view::TextView*>(view)->getModel());    
        case view::View::HUD_VIEW :
            return new graphic::amazin::HUDViewPainter(dynamic_cast<view::HUDView*>(view)->getModel());     
        case view::View::MAP_VIEW :
            return new graphic::amazin::MapViewPainter(dynamic_cast<view::MapView*>(view)->getModel());              
        case view::View::MINI_MAP_VIEW :
            return new graphic::amazin::MiniMapViewPainter(dynamic_cast<view::MiniMapView*>(view)->getModel());  
        case view::View::WAR_VIEW :
            return new graphic::amazin::WarViewPainter(dynamic_cast<view::WarView*>(view)->getModel());  
	}


}


}
}



