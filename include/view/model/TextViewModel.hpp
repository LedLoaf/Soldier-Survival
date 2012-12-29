#ifndef TEXT_VIEW_MODEL_HPP_
#define	TEXT_VIEW_MODEL_HPP_

#include <string>
#include <view/model/ViewModel.hpp>
#include <view/TextView.hpp>


namespace view { 
    
    
class TextViewModel : public ViewModel {
public:
    TextViewModel();

    void setText(std::string text);
    std::string getText();
    
    void setTextViewType(TextView::TextType type);
    TextView::TextType getTextViewType();
        
private:
    std::string text;
    TextView::TextType textType; 
};

}

#endif	

