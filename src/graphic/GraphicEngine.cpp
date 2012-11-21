
void display() {
	updatePainters();

	//  display
	displayGraphicFromPainters();
}


void updatePainters() {
	if (!isPaintingCurrentWindow())
		initWindowPainters(Application.getContext().getActiveWindow());

	for (Painter painter : windowPainters) {
		painter.update();
	}
}


void initWindowPainters(Window& window) {
	painters.clear();

	for (View view : window.getViews()) {
		painters.add(getPainterForView(view))
	}
}


bool isPaintingCurrentWindow() {
	if (currentWindowPainting == Application.getContext().getActiveWindow())
		return true;
	return false;
}


void displayGraphicFromPainters() {
	for (Painter p : painters) 
		for (Sprite sprite : p.getSprites())
			smflWindow->Draw(sprite);
}
