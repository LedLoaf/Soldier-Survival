#include <util/DeviceManager.hpp>

namespace util {

DeviceManager::DeviceManager() {
	// TODO Auto-generated constructor stub

}

DeviceManager::~DeviceManager() {
	// TODO Auto-generated destructor stub
}

int DeviceManager::setScreenWidth(int width) {
    this->screenWidth = width;
}
int DeviceManager::setScreenHeight(int height){
    this->screenHeight = height;
}


int DeviceManager::getScreenWidth() {
    return screenWidth;
}

int DeviceManager::getScreenHeight() {
    return screenHeight;
}

} /* namespace util */
