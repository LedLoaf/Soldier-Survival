#ifndef SFML_AMAZIN_RESOURCE_HPP_
#define SFML_AMAZIN_RESOURCE_HPP_

#include <string>
#include <map>
#include <SFML/Graphics/Image.hpp>

#include <view/View.hpp>
#include <view/model/MapViewModel.hpp>
#include <game/object/MapObject.hpp>

namespace util {

class SFMLAmazinResource {
public:     
	static SFMLAmazinResource* getInstance();
    
    sf::Image* getImage(game::MapObject::Type mapObjectType);
    sf::Image* getTransparentImage();
    

private:
	static SFMLAmazinResource* instance;
    std::map<game::MapObject::Type, sf::Image*> imageResourceMap;
    std::map<game::MapObject::Type, sf::Image*> equipmentItemImageResourceMap;
    sf::Image* imageNotFound;
    sf::Image* transparentImage;
    
    SFMLAmazinResource();    
    void init();
    
    void initMapObjectImages();
    void initEquipmentItemImages();
    void initSpecialImages();

};

}
#endif