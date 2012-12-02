/*
 * SelectionViewModel.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef SELECTIONVIEWMODEL_HPP_
#define SELECTIONVIEWMODEL_HPP_

#include <util/Util.hpp>
#include <vector>
#include <iostream>

#include <view/View.hpp>

namespace view {

class SelectionViewModel : public ViewModel {
public:
	class SelectableElement;

	SelectionViewModel();
	virtual ~SelectionViewModel();

    std::vector<SelectableElement*> getSelectableElements();
    
	void setSelected(int positionOfElement);
	void setUnselected(int positionOfElement);
	int getSize();

    void addElement(SelectableElement* element);


	class SelectableElement {
	public:
        void setAction(Util::Action action);
		Util::Action getAction();
		void setUnselected();
		void setSelected();
        int getId();
        bool isSelected();

        util::Location::Position getPosition();
        void setPosition(util::Location::Position position);

        
        int setElementWidth(int width);
        int setElementHeight(int height);   
        
        int getElementWidth();
        int getElementHeight();        
        
	private:
		bool selected;
        Util::Action action;
        int elementWidth, elementHeight;
        //Orientation orientation;
        
	};



private:
	std::vector<SelectableElement*> selectableElements;

};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
