#include "UAV/listeners/StatusTextListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/PacketReceivedEvent.hpp"
#include "UAV/Log.hpp"

namespace UNL::UAV::Listener{
	void StatusTextListener::onEvent(UNL::UAV::Event::Event* e){
		UNL::UAV::Events::PacketReceivedEvent* PRE = static_cast<UNL::UAV::Events::PacketReceivedEvent*>(e);
		mavlink_message_t msg = PRE->getMessage();
		if(msg.msgid != MAVLINK_MSG_ID_STATUSTEXT){ // no need to continue on at this point.
			return;
		}

		mavlink_statustext_t status;
		mavlink_msg_statustext_decode(&msg, &status);

		switch(status.severity){
			case MAV_SEVERITY_EMERGENCY:
				UNL::UAV::Log::getReader()->critical(status.text);
				break;
			case MAV_SEVERITY_ALERT:
				UNL::UAV::Log::getReader()->warn(status.text);
				break;
			case MAV_SEVERITY_CRITICAL:
				UNL::UAV::Log::getReader()->critical(status.text);
				break;
			case MAV_SEVERITY_ERROR:
				UNL::UAV::Log::getReader()->error(status.text);
				break; 
			case MAV_SEVERITY_WARNING:
				UNL::UAV::Log::getReader()->warn(status.text);
				break;
			case MAV_SEVERITY_NOTICE:
				UNL::UAV::Log::getReader()->info(status.text);
				break; 
			case MAV_SEVERITY_INFO:
				UNL::UAV::Log::getReader()->info(status.text);
				break;
			case MAV_SEVERITY_DEBUG:
				UNL::UAV::Log::getReader()->debug(status.text);
				break;
		}
	}
}