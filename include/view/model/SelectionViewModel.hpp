/*
 * SelectionViewModel.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef SELECTIONVIEWMODEL_HPP_
#define SELECTIONVIEWMODEL_HPP_

#include <util/Action.hpp>
#include <vector>
#include <iostream>

namespace view {

class SelectionViewModel : ViewModel {
public:
	class SelectableElement;


	SelectionViewModel();
	virtual ~SelectionViewModel();

	std::vector<SelectableElement>* getSelectableElements();
	void setSelected(int positionOfElement);
	void setUnselected(int positionOfElement);
	int getSize();



	class SelectableElement {
	public:
		util::Action getAction();
		void setUnselected();
		void setSelected();
	private:
		bool isSelected;
	};



private:
	std::vector<SelectableElement&> selectableElements;

};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
