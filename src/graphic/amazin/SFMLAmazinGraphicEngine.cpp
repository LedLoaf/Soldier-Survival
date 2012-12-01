
#include <graphic/amazin/SFMLAmazinGraphicEngine.hpp>
#include <view/window/Window.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace graphic {
namespace amazin {


virtual SFMLAbstractViewPainter& SFMLAmazinGraphicEngine::getPainterForView(const view::View& view) {
	switch (view.getType()) {
	case view::View::Type::SELECTION_VIEW:
		return new graphic::amazin::SelectionViewPainter(((view::SelectionViewModel) view).getModel());
	}


}


}
}



