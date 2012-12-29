#include <view/TextView.hpp>
#include <string>


namespace view {

TextView::TextView(int xStart, int yStart, int xEnd, int yEnd, std::string text, TextView::TextType type) : View(xStart, yStart, xEnd, yEnd) {
    this->textViewModel = new TextViewModel();
    textViewModel->setText(text);
    textViewModel->setTextViewType(type);
}


TextViewModel* TextView::getModel() {
    return this->textViewModel;
}

view::View::Type TextView::getType() {
    return view::View::TEXT_VIEW;
}

}