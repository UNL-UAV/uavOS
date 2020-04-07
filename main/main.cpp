/*

	Code that is responsible for the Source executable in bin.

*/

#include "pch.hpp"
#include "UAV/uavOS.hpp"
#include "common/mavlink.h"
#include "UAV/Log.hpp"
#include "UAV/listeners/SerialReadListener.hpp"
#include "UAV/listeners/StatusTextListener.hpp"
#include "UAV/listeners/ParamValueListener.hpp"
#include "UAV/listeners/command/ArmedListener.hpp"
#include "cxxopts.hpp"

int main(int argc, char** argv){
	//Beginning the set-up
	cxxopts::Options options("uavOS", "Interface with the Computer and the PixHawk");
	options.add_options()
		("p,port", "Port", cxxopts::value<std::string>())
		("r,rate", "Baudrate", cxxopts::value<int>()->default_value("57600"))
		("h,help", "Help")
	;

	//The commands given in command line are parsed
	auto result = options.parse(argc, argv);

	if(result.count("help")){
		std::cout << options.help() << std::endl;
		return 0;
	}

	if(!result.count("port") || !result.count("rate")){
		std::cout << "Not enought arguments use --help for more help!" << std::endl;
		return -1;
	}

	std::string port = result["port"].as<std::string>();
	int rate = result["rate"].as<int>();
	//Ending the set-up

	//initializes the log
	UNL::UAV::Log::init();

	//starts the serial interface
	UNL::UAV::Serial serial(port, rate);

	UNL::UAV::Application app(serial);

	UNL::UAV::Listener::SerialReadListener srl;
	app.addReadListener(srl);

	UNL::UAV::Listener::StatusTextListener stl;
	app.addReadListener(stl);

	//UNL::UAV::Listener::ParamValueListener pvl;
	//app.addReadListener(pvl);
	
	UNL::UAV::Listener::Command::ArmedListener al;
	app.addCommand(al);
	
	app.init();
	while(app.isRunning()){
		app.update();
	}
	return 0;
}