class MainMenuWindow : Window {
public:
	MainMenuWindow() {
		initModel();
		initUI();
	}

	void initModel() {
		mainMenuSelectionModel = new MainMenuSelectionModel();
	}

	void initUI() {
		// x, y, width, height, model
		selectionView = new SelectionView(100, 100, 150, 400, mainMenuSelectionModel);
		addView(mainMenuSelectionView);


		mainMenuLogoPath = Application.getResourceManager().getPath(Resource.MAIN_MENU_LOGO);

		addView(new ImageView(100, 0, 150, 200, mainMenuLogoPath));
	}


	void onArrowPressed(arrow) {
		if (arrow == down) {
			if (mainMenuSelectionView.hasNextOption())
				mainMenuSelectionView.selectNextOption();
		}


	}


	List<View> getViews() {
		return childViews;
	}



	void onEnterPressed() {
		Action optionAction = mainMenuSelectionView.getSelectedElement().getAction();

		switch(optionAction) {
			case: Action.RUN_LEVEL_SELECTION
				Application->getGameEngine()->runLevelSelection();
		
			case Action.RUN_EXIT
				gameEngine.exitGame();
		}
	}

};
