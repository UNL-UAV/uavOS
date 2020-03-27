#include "pch.hpp"
#include "UAV/uavOS.hpp"
#include "common/mavlink.h"
#include "UAV/Log.hpp"
#include "UAV/listeners/SerialReadListener.hpp"
int main(int argc, char** argv){
	UNL::UAV::Log::init();
	UNL::UAV::Log::getLogger()->info("Starting to connect to PIXHAWK");
	std::string port = "/dev/ttyACM0";
	UNL::UAV::Serial serial(port, 9600);
	UNL::UAV::Application app(serial);
	
	UNL::UAV::Listener::SerialReadListener srl;
	app.addReadListener(srl);
	
	app.init();
	while(app.isRunning());
	return 0;
}
