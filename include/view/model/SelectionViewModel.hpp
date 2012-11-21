/*
 * SelectionViewModel.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef SELECTIONVIEWMODEL_HPP_
#define SELECTIONVIEWMODEL_HPP_

#include <list>

namespace view {

class SelectionViewModel {
public:
	class SelectableElement;


	SelectionViewModel();
	virtual ~SelectionViewModel();

	List<SelectableElement>* getSelectableElements();


	List<SelectableElement> selectableElements;




	class SelectableElement {

	};
};

} /* namespace view */
#endif /* SELECTIONVIEWMODEL_HPP_ */
