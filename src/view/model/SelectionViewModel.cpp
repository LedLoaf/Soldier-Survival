class MainMenuSelectionModel { 
private:
	void init() {
		SelectableElement selectableElement = new SelectableElement("Play");

		selectableElement.setTitle("Play");
		selectableElement.setAction(Action.RUN_LEVEL_SELECTION);
		mSelectableElements.add(selectableElement);


		selectableElement.setTitle("About");
		selectableElement.setAction(Action.RUN_ABOUT);
		mSelectableElements.add(selectableElement);

		selectableElement.setTitle("Exit");
		selectableElement.setAction(Action.RUN_EXIT);
		mSelectableElements.add(selectableElement);

	}

public:

	List<SelectableElement> getSelectableElements() {
		return mSelectableElements;
	}

}