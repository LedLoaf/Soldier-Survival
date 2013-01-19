#ifndef TEXT_VIEW_HPP_
#define TEXT_VIEW_HPP_

#include <view/View.hpp>
#include <iostream>


namespace view {

class TextViewModel; 
    
    
class TextView : public View {
public:
    enum TextType {
        SMALL, MIDDLE
    };
    
    TextView(int xStart, int yStart, int xEnd, int yEnd, std::string text, TextView::TextType type);
    
    TextViewModel* getModel();
	virtual Type getType();
    virtual bool hasEmptyModel();
    
        
private:
    TextViewModel* textViewModel;
};

}
#endif
