#ifndef RESOURCE_HPP_
#define RESOURCE_HPP_

#include <string>

#include <view/View.hpp>


namespace util {

class Resource {
public:     
    class MainMenuResourceManager;
    class GamePlayResourceManager;
    
    enum Type {
        MAIN_MENU_LOGO, GAME_PLAY_LOGO
    };
    
    virtual std::string getPath(Resource::Type resourcePath) = 0;
    
    static Resource* getResourceManagerFor(view::View::Type windowType);
   

private:
    static Resource* mainMenuResourceManager;
    static Resource* gamePlayResourceManager;

};


class Resource::MainMenuResourceManager : Resource {
public:
    virtual std::string getPath(Resource::Type resourcePath);

};    


class Resource::GamePlayResourceManager : Resource {
public:
    virtual std::string getPath(Resource::Type resourcePath);

};     

}
#endif