#ifndef IMAGE_VIEW_HPP_
#define IMAGE_VIEW_HPP_

#include <view/View.hpp>
#include <iostream>
#include <list>

#include <view/model/ImageViewModel.hpp>


namespace view {

class ImageView : public View {
public:
    ImageView(int xStart, int yStart, int xEnd, int yEnd, util::Resource::Type resource);
    void setModel(ImageViewModel* model);
    ImageViewModel* getModel();
    
	virtual Type getType();
    
        
private:
    ImageViewModel* imageViewModel;
};

}
#endif
