#ifndef MAIN_MENU_WINDOW_HPP_
#define MAIN_MENU_WINDOW_HPP_

#include <view/window/Window.hpp>
#include <view/SelectionView.hpp>

class MainMenuWindow : Window {
public:
	MainMenuWindow();
	initModel();

private:
	SelectionView* selectionView;
};

#endif


class MainMenuWindow : Window {
public:
	MainMenuWindow() {
		initModel();
		initUI();
	}

	void initModel() {
		selectionModel = new SelectionViewModel();
		selectionModel.addElement(new SelectionViewModel::SelectableElement("Play", Action.RUN_LEVEL_SELECTION));
		selectionModel.addElement(new SelectionViewModel::SelectableElement("Options", Action.RUN_OPTIONS));
		selectionModel.addElement(new SelectionViewModel::SelectableElement("Exit", Action.RUN_EXIT_APPLICATION));

	}

	void initUI() {
		// x, y, width, height, model
		selectionView = new SelectionView(100, 100, 150, 400);
		selectionView.setModel(selectionModel);

		addView(mainMenuSelectionView);


		mainMenuLogoPath = Application.getResourceManager().getPath(Resource.MAIN_MENU_LOGO);

		ImageView logoView = new ImageView(100, 0, 150, 200);
		logoView.setBitmapPath(mainMenuLogoPath);

		addView(logoView);
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


