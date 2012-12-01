#ifndef SELECTION_VIEW_PAINTER_HPP_
#define SELECTION_VIEW_PAINTER_HPP_

#include <graphic/painter/SFMLAbstractViewPainter.hpp>

namespace graphic {
namespace amazin {

class SelectionViewPainter : SFMLAbstractViewPainter {
public:
	SelectionViewPainter(view::SelectionViewModel& model);

	void init();
	void update();

private:
	view::SelectionViewModel& model;

};

}
}


#endif
