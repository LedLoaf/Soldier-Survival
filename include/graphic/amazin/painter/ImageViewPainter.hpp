#ifndef IMAGE_VIEW_PAINTER_HPP_
#define IMAGE_VIEW_PAINTER_HPP_

#include <view/View.hpp>
#include <view/model/ImageViewModel.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>
#include <map>


namespace graphic {
namespace amazin {

class ImageViewPainter : public SFMLAbstractViewPainter {
public:
	ImageViewPainter(view::ImageViewModel* model, view::View::Type parentViewType);
    

	virtual void init();
	virtual void update();
    
    

private:
	view::ImageViewModel* imageViewModel;

};

}
}


#endif
