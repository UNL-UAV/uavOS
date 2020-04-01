#include "UAV/listeners/command/ArmedListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/CommandReceivedEvent.hpp"
#include "UAV/Log.hpp"



namespace UNL::UAV::Listener::Command{

	void ArmedListener::onEvent(UNL::UAV::Event::Event* e){
		CommandListener::onEvent(e);
	}
	void ArmedListener::processCommand(){
		UNL::UAV::Log::getReader()->info("Command Received!");
		std::string str = this->_event->getCommandString();
		std::istringstream iss(str);
		std::vector<std::string> spl(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

		if(spl.size() > 0){
			if(spl[0] == "arm"){
				UNL::UAV::Log::getReader()->info("Arming..");
			}
		}
	}
}