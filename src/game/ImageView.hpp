#ifndef IMAGEVIEW_HPP_
#define	IMAGEVIEW_HPP_

#include <view/View.hpp>

namespace view {
        
class ImageView : View {
private:
	ImageViewModel& imageViewModel;

public:
	ImageView(ImageViewModel& model) {
		this->imageViewModel = model;
	}
	
};

}

#endif	/* IMAGEVIEW_HPP_ */

