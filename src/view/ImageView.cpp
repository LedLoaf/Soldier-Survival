#include <game/Application.hpp>
#include <view/ImageView.hpp>
#include <string>


namespace view {

ImageView::ImageView(int xStart, int yStart, int xEnd, int yEnd, util::Resource::Type resource) : View(xStart, yStart, xEnd, yEnd) {
    imageViewModel = new ImageViewModel();
    imageViewModel->setViewPosition(new util::Location::Position(xStart, yStart), new util::Location::Position(xEnd, yEnd));
}

void ImageView::setModel(ImageViewModel* model) {
	this->imageViewModel = model;
}

ImageViewModel* ImageView::getModel() {
	return this->imageViewModel;
}

view::View::Type ImageView::getType() {
    return view::View::IMAGE_VIEW;
}

}