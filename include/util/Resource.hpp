#ifndef RESOURCE_HPP_
#define RESOURCE_HPP_

#include <string>

#include <view/View.hpp>


namespace util {

class Resource {
public:     
    class MainMenuResourceManager;
    class GamePlayResourceManager;
    
    enum Path {
        MAIN_MENU_LOGO
    };
    
    virtual std::string getPath(Resource::Path resourcePath) = 0;
    
    static Resource* getResourceManagerFor(view::View::Type windowType);
   

private:
    static Resource* mainMenuResourceManager;
    static Resource* gamePlayResourceManager;

};


class Resource::MainMenuResourceManager : Resource {
public:
    virtual std::string getPath(Resource::Path resourcePath);

};    


class Resource::GamePlayResourceManager : Resource {
public:
    virtual std::string getPath(Resource::Path resourcePath);

};     

}
#endif