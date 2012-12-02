/* 
 * File:   ImageViewModel.cpp
 * Author: yet1
 * 
 * Created on December 1, 2012, 11:08 PM
 */

#include <view/model/ImageViewModel.hpp>

namespace view {
    
ImageViewModel::ImageViewModel() {
}

ImageViewModel::ImageViewModel(const ImageViewModel& orig) {
}

ImageViewModel::~ImageViewModel() {
}

void ImageViewModel::setImagePath(std::string path) {
   this->imagePath = path; 
}

std::string ImageViewModel::getImagePath() {
   return this->imagePath;
}

}

