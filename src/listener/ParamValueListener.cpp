#include "UAV/listeners/ParamValueListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/PacketReceivedEvent.hpp"
#include "UAV/Log.hpp"

namespace UNL::UAV::Listener{
	void ParamValueListener::onEvent(UNL::UAV::Event::Event* e){
		UNL::UAV::Events::PacketReceivedEvent* PRE = static_cast<UNL::UAV::Events::PacketReceivedEvent*>(e);
		mavlink_message_t msg = PRE->getMessage();
		if(msg.msgid != MAVLINK_MSG_ID_STATUSTEXT){ // no need to continue on at this point.
			return;
		}

		mavlink_param_value_t param;
		mavlink_msg_param_value_decode(&msg, &param);

		UNL::UAV::Log::getReader()->info("param "+std::string(param.param_id) +":"+ std::to_string(param.param_value));
	}
}