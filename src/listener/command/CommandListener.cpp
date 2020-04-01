#include "UAV/listeners/command/CommandListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/CommandReceivedEvent.hpp"
#include "UAV/Log.hpp"

namespace UNL::UAV::Listener::Command{
	void CommandListener::onEvent(UNL::UAV::Event::Event* e){
		UNL::UAV::Events::CommandReceivedEvent* AE = static_cast<UNL::UAV::Events::CommandReceivedEvent*>(e);
		this->_event = AE;
		this->processCommand();
	}
}