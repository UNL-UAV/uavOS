#include "pch.hpp"
#include "UAV/uavOS.hpp"
#include "common/mavlink.h"

int main(int argc, char** argv){
	std::string port = "/dev/cu.usbmodem14101";
	UNL::UAV::Serial serial(port, 57600);
	UNL::UAV::Application app(serial);
	app.init();
	while(app.isRunning());
	return 0;
}
