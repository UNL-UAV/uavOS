#include "UAV/listeners/HeatbeatListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/PacketReceivedEvent.hpp"
#include "UAV/Log.hpp"

namespace UNL::UAV::Listener{
	void SerialReadListener::onEvent(UNL::UAV::Event::Event* e){
		UNL::UAV::Events::PacketReceivedEvent* PRE = static_cast<UNL::UAV::Events::PacketReceivedEvent*>(e);
		mavlink_message_t msg = PRE->getMessage();
		if(msg.msgid != MAVLINK_MSG_ID_HEARTBEAT){ // no need to continue on at this point.
			return;
		}

		mavlink_heartbeat_t heartbeat;
		mavlink_msg_heartbeat_decode(msg, &heartbeat);

		//PRE->getSerial().write(); // send the heartbeat.
	}
}