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

namespace view {
    

class ImageViewModel : public ViewModel {
public:
    ImageViewModel();
    ImageViewModel(const ImageViewModel& orig);
    virtual ~ImageViewModel();

    void setImagePath(std::string path);
    std::string getImagePath();
        
private:
    std::string imagePath; 
};

}

#endif	/* IMAGEVIEWMODEL_HPP */

