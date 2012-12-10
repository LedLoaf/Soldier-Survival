#include <util/Resource.hpp>
#include <string>

namespace util {

Resource* Resource::mainMenuResourceManager;
Resource* Resource::gamePlayResourceManager;


Resource* Resource::getResourceManagerFor(view::View::Type windowType) {
    if (windowType == view::View::MAIN_MENU_WINDOW) {
        return mainMenuResourceManager;
    }    
}


std::string Resource::MainMenuResourceManager::getPath(Resource::Type resourcePath) {

}

std::string Resource::GamePlayResourceManager::getPath(Resource::Type resourcePath) {

}



}
