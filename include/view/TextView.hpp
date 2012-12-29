#ifndef TEXT_VIEW_HPP_
#define TEXT_VIEW_HPP_

#include <view/View.hpp>
#include <iostream>

class TextViewModel; //czenu nie mozna po prostu #include <view/model/TextViewModel.hpp> ?

namespace view {

class TextView : public View {
public:
    enum TextType {
        SMALL
    };
    
    TextView(int xStart, int yStart, int xEnd, int yEnd, std::string text, TextView::TextType type);
    
    TextViewModel* getModel();
	virtual Type getType();
    
        
private:
    TextViewModel* textViewModel;
};

}
#endif
