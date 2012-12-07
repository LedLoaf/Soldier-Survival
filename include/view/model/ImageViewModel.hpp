/* 
 * File:   ImageViewModel.hpp
 * Author: yet1
 *
 * Created on December 1, 2012, 11:08 PM
 */

#ifndef IMAGEVIEWMODEL_HPP
#define	IMAGEVIEWMODEL_HPP
#include <string>
#include <view/model/ViewModel.hpp>
#include <util/Resource.hpp>

namespace view {
    

class ImageViewModel : public ViewModel {
public:
    ImageViewModel();
    ImageViewModel(const ImageViewModel& orig);
    virtual ~ImageViewModel();

    void setImageResource(util::Resource::Type resource);
    util::Resource::Type getImageResource();
        
private:
    util::Resource::Type imageResource; 
};

}

#endif	/* IMAGEVIEWMODEL_HPP */

