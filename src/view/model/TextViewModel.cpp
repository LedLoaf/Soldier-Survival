#include <view/model/TextViewModel.hpp>

namespace view {
    
void TextViewModel::setText(std::string text) {
    this->text = text;
}

std::string TextViewModel::getText() {
    return text;
}

void TextViewModel::setTextViewType(TextView::TextType type) {
    this->textType = type;
}

TextView::TextType TextViewModel::getTextViewType() {
    return textType;
}
            


}

