class MapView : View {
private:
	// MapViewModel jest doslownie modelem - nie ma zadnej konkretnej logiki, trzyma tylko 2 tablice 2 wymiarowe z mapa
	MapViewModel mapModel;

public:

	MapView(LevelDescription& levelDescription) {
		generateMapModel(levelDescription);
	}

	void moveCharacter(Character& ch, vector) {
		// getPositionOf() jest generyczna - mozna tam podac np. referencje do danego kafeleku rzeki
		Position position = mapModel->getPositionOf(ch);

		mapModel->removeCharacterFrom(position);

		// tutaj sobie przeladujemy '+' w position, zeby zwrocil nam nowa pozycje przesunieta o dany wektor w stosunku
		// do starej
		mapModel->put(character, position + vector);
	}


	bool canMoveCharacter(vector) {
		// MapView gra role MapHandlera
		// sprawdzam w tablicy z mapa czy jest taka mozliwosc
	}


	void generateMapModel(LevelDescription& levelDescription) {
		// tworze drogi, rzeki, postacie, itd
		// wszystko w MapViewModel

		// x, y kafelek - tam umieszczam Enemy

		/*
		 Character dostaje referencje do tego widoku, zeby mogl sie poruszac
			kozystajac z metod canMoveCharacter() i moveCharacter()
		 */


		mapModel.add(x, y, new Enemy(this))
	}

	
}