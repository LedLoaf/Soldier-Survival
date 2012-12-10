#ifndef TEXT_VIEW_MODEL_HPP
#define	TEXT_VIEW_MODEL_HPP

#include <string>
#include <view/model/ViewModel.hpp>
#include <util/Resource.hpp>

namespace view {
    

class TextViewModel : public ViewModel {
public:
    TextViewModel();
    TextViewModel(const ImageViewModel& orig);
    virtual ~TextViewModel();

    void setText(std::string text);
    std::string getText();
    
    void setTextViewType(view::TextView::TextType type);
    view::TextView::TextType getTextViewType();
        
private:
    std::string text;
    view::TextView::TextType textType; 
};

}

#endif	

