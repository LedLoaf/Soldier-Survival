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

	static int getScreenWidth();
	static int getScreenHeight();

};

} /* namespace util */
#endif /* DEVICEMANAGER_HPP_ */
