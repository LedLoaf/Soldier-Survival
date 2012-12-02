#ifndef SELECTION_VIEW_HPP_
#define SELECTION_VIEW_HPP_

#include <view/View.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <iostream>
#include <list>


namespace view {

class SelectionView : public View {
public:
    SelectionView(int xStart, int yStart, int xEnd, int yEnd) : View(xStart, yStart, xEnd, yEnd) {}
	void selectNextElement();
	bool hasNextElement();
	SelectionViewModel::SelectableElement* getSelectedElement();
    void setSelectionModel(SelectionViewModel* selectionViewModel);
    virtual Type getType();
    SelectionViewModel* getModel();
    
    

private:
	SelectionViewModel* selectionModel;
	int positionOfSelectedElement;
    
	
};

}
#endif
