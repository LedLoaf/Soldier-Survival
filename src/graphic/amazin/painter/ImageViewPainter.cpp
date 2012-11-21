class ImageViewPainter : ViewPainter {

	ImageViewPainter(String bitmapPath) {
		this.bitmapPath = bitmapPath;

		init();
	}

	void init() {

			// klucz wartosc, mapa
			sprites.add(element.getId(), new Sprite(x, y, ..., model.getBitmap()));

	}


	void update() {
	}


	List<Sprite> getSprites() {
		return sprites;
	}
};