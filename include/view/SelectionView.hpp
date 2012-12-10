#ifndef SELECTION_VIEW_HPP_
#define SELECTION_VIEW_HPP_

#include <view/View.hpp>
#include <view/model/SelectionViewModel.hpp>
#include <iostream>
#include <list>


namespace view {

class SelectionView : public View {
public:

    SelectionView(int xStart, int yStart, int xEnd, int yEnd, SelectionViewModel::Type modelType);
    
    void setOrientation(view::View::Orientation orientation);
    
 	void selectPreviousElement();   
	void selectNextElement();
    bool hasPreviousElement();
	bool hasNextElement();
    
    void selectElement(int pos);
    
	SelectionViewModel::SelectableElement* getSelectedElement();
    void setSelectionModel(SelectionViewModel* selectionViewModel);
    virtual Type getType();
    SelectionViewModel* getModel();
    
    void addElement(SelectionViewModel::SelectableElement* element);
    
    

private:
	SelectionViewModel* selectionModel;
	int positionOfSelectedElement;    
	
};

}
#endif
