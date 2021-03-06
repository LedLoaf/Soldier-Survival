#include <view/TextView.hpp>
#include <string>

#include <view/model/TextViewModel.hpp>

namespace view {

TextView::TextView(int xStart, int yStart, int xEnd, int yEnd, std::string text, TextView::TextType type) : View(xStart, yStart, xEnd, yEnd) {
    textViewModel = new TextViewModel();
    textViewModel->setText(text);
    textViewModel->setTextViewType(type);
    textViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
}


TextViewModel* TextView::getModel() {
    return this->textViewModel;
}

view::View::Type TextView::getType() {
    return view::View::TEXT_VIEW;
}


bool TextView::hasEmptyModel() {
    if (textViewModel == NULL)
        return true;
    else
        return false;
}
}