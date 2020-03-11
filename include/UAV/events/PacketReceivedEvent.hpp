#pragma once
#include "../Core.hpp"
#include "../event/Event.hpp"
#include "common/mavlink.h"

namespace UNL::UAV::Events{
	class _API PacketReceivedEvent : public UNL::UAV::Event::Event{
	private:
		mavlink_message_t _message;
	public:
		PacketReceivedEvent(const mavlink_message_t& message) : _message(message){}
		inline const mavlink_message_t& getMessage() const {return _message;};
	};
}