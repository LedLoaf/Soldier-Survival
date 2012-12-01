#include <graphic/amazin/painter/SelectionViewPainter.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <algorithm>
#include <vector>

namespace graphic {
namespace amazin {

SelectionViewPainter::SelectionViewPainter(view::SelectionViewModel& model) {
	this->model = model;

	init();
}

void initSelectableSprite(view::SelectionViewModel::SelectableElement& selectableElement) {
	sprites.insert(std::pair<int, Sprite&>(selectableElement.getId(), new Sprite(selectableElement));
}

void updateSelectableSprite(view::SelectionViewModel::SelectableElement& selectableElement) {

	if (selectableElement.isSelected())
		sprites.get(element.getId()).setColor(zaznaczony);
	else
		sprites.get(element.getId()).setColor(niezaznaczony);
}


void SelectionViewPainter::init() {
	for_each (selectableElements.begin(), selectableElements.end(), initSelectableSprite);
}


void SelectionViewPainter::update() {
	for_each (selectableElements.begin(), selectableElements.end(), updateSelectableSprite);
}

}
}

#endif
