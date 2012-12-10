#ifndef SFML_AMAZIN_RESOURCE_HPP_
#define SFML_AMAZIN_RESOURCE_HPP_

#include <string>

#include <view/View.hpp>

#include <SFML/Graphics/Image.hpp>

namespace util {

class SFMLAmazinResource {
public:     
	static SFMLAmazinResource* getInstance();
    
    sf::Image* getImage(view::MapViewModel::Element element);
    

private:
	static SFMLAmazinResource* instance;
    std::map<view::MapViewModel::Element, sf::Image*> imageResourceMap;
    
    SFMLAmazinResource();    
    void init();

};

}
#endif