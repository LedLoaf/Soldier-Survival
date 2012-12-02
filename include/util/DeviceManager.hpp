/*
 * DeviceManager.hpp
 *
 *  Created on: Nov 20, 2012
 *      Author: yet1
 */

#ifndef DEVICEMANAGER_HPP_
#define DEVICEMANAGER_HPP_

namespace util {

class DeviceManager {
public:
	DeviceManager();
	virtual ~DeviceManager();

    int setScreenWidth(int width);
    int setScreenHeight(int height);

    
	int getScreenWidth();
	int getScreenHeight();
private:
    int screenHeight, screenWidth;

};

} /* namespace util */
#endif /* DEVICEMANAGER_HPP_ */
