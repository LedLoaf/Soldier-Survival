class MapViewPainter : ViewPainter {

	MapViewPainter(MapViewModel model) {
		this.model = model;

		init();
	}

	void init() {

		for (MapElement element : model.getSelectableElements()) {

			// klucz wartosc, mapa
			sprites.add(element.getId(), new Sprite(x, y, ..., model.getTitle()));

		}
	}


	void createWorldSprites() {
		int mapWidth = model.getMapWidth();
		int mapHeight = model.getMapHeight();

		GameObject mapWorld[mapWidth][mapHeight] = model.getMapWorld();

		for (int i = 0; i < mapHeight; i++) 
			for (int j = 0; j < mapWidth; j++) 
				sprites.add(createSpriteFrom(mapWorld[i][j])); //createSpriteFrom(GameObject)
	}

	Sprite& createSpriteFrom(GameObject gameObject) {

		Resource gameObjectResource = Application->getContext()->getResourceManager()->getResource(gameObject); // np. Resource.MAP_VIEW_ENEMY

		String spritePath = Application->getContext()->getResourceManager()->getPath(gameObjectResource);

		return new Sprite(..., spritePath);
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