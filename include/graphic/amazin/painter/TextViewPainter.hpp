#ifndef TEXT_VIEW_PAINTER_HPP_
#define TEXT_VIEW_PAINTER_HPP_

#include <view/View.hpp>
#include <graphic/painter/SFMLAbstractViewPainter.hpp>


namespace graphic {
namespace amazin {

class TextViewPainter : public SFMLAbstractViewPainter {
public:
	TextViewPainter(view::TextViewModel* textViewModel);
    

	virtual void init();
	virtual void update();
    
    

private:
    view::TextViewModel* textModel;
};

}
}


#endif
