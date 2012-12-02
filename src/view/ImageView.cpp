#include <view/ImageView.hpp>

namespace view {

void ImageView::setModel(ImageViewModel& model) {
	this->imageViewModel = model;
}

}