#ifndef IMAGE_VIEW_HPP_
#define IMAGE_VIEW_HPP_

#include <view/View.hpp>
#include <iostream>
#include <list>

#include <view/model/ImageViewModel.hpp>


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
