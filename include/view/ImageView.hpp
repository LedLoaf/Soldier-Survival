#ifndef IMAGE_VIEW_HPP_
#define IMAGE_VIEW_HPP_

#include <view/View.hpp>
#include <iostream>
#include <list>

#include <view/model/ImageViewModel.hpp>


namespace view {

class ImageView : View {
public:
//    ImageView(int xStart, int yStart, int xEnd, int yEnd);
    void setModel(ImageViewModel& model);
        
private:
    ImageViewModel& imageViewModel;
};

}
#endif
