LevelSelectionWindow() {
	this.levelChoiceWindow = new ChoiceWindow();
	this.levelDescriptionWindow = new Window();
}


// laduj wybrany level
void onEnterPressed() {
	WindowOption selectedOption = levelChoiceWindow->getSelectedOption();

	// bedzie tak: gameEngine->loadLevel(levelDescription);
	gameEngine->(selectedOption->getIntent());

	// inaczej
	//selectedOption->runAction(gameEngine);


	~levelChoiceWindow();
	~levelDescriptionWindow();
}


void onArrowPressed(arrow) {

	/*
		Tak jak mamy na tych szkichach UI: 
		1. przycisnalem strzalke w dol
		2. levelChoiceWindow->selectNextOption() sprawia, ze 
			kolejna nazwa lewelu sie podswietla (oznacza to, ze na nim aktualnie jestem)
		3. levelDescriptionWindow->setModel(levelChoiceWindow->getSelectedOption()->getModel())
			sprawia, ze po prawej stronie (w tym oknie opisu levelu) pojawia sie opis wybranego levelu
	}
	*/
	if (arrow == down)	{
		levelChoiceWindow->selectNextOption(); 
		levelDescriptionWindow->setModel(levelChoiceWindow->getSelectedOption()->getModel());
	} .. up

}