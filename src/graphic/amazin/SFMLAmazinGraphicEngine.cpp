
#include <graphic/amazin/SFMLAmazinGraphicEngine.hpp>
#include <view/View.hpp>
#include <view/window/Window.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <view/SelectionView.hpp>
#include <graphic/amazin/painter/SelectionViewPainter.hpp>
 

namespace graphic {
namespace amazin {


SFMLAbstractViewPainter* SFMLAmazinGraphicEngine::getPainterForView(view::View* view) {
	switch (view->getType()) {
        case view::View::SELECTION_VIEW :
            return new graphic::amazin::SelectionViewPainter(dynamic_cast<view::SelectionView*>(view)->getModel());
	}


}


}
}



