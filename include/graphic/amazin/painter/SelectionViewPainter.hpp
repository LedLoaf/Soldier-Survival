#ifndef SELECTION_VIEW_PAINTER_HPP_
#define SELECTION_VIEW_PAINTER_HPP_


class SelectionViewPainter : ViewPainter {

	SelectionViewPainter(ViewModel model) {
		this.model = model;

		init();
	}

	void init() {

		for (SelectableElement element : model.getSelectableElements()) {

			// klucz wartosc, mapa
			sprites.add(element.getId(), new Sprite(x, y, ..., element.getTitle()));

		}
	}


	void update() {


		for (SelectableElement element : model.getSelectableElements()) {

			if (element.isSelected())
				sprites.get(element.getId()).setColor(zaznaczony);
			else 
				sprites.get(element.getId()).setColor(niezaznaczony);

		}

	}


	List<Sprite> getSprites() {
		return sprites;
	}
};

#endif
