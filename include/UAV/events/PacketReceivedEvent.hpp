#pragma once
#include "../Core.hpp"
#include "../event/Event.hpp"
#include "../Serial.hpp"
#include "common/mavlink.h"

namespace UNL::UAV::Events{
	class _API PacketReceivedEvent : public UNL::UAV::Event::Event{
	private:
		mavlink_message_t _message;
		UNL::UAV::Serial _serial;
	public:
		PacketReceivedEvent(const UNL::UAV::Serial& serial, const mavlink_message_t& message) : _message(message), _serial(serial){}
		inline const mavlink_message_t& getMessage() const {return _message;};
		inline const UNL::UAV::Serial getSerial() const {return _serial;}
	};
}