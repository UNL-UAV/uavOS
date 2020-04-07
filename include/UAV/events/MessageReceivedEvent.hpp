#pragma once
#include "../Core.hpp"
#include "pch.hpp"
#include "../event/Event.hpp"
#include "../Serial.hpp"
#include "common/mavlink.h"

namespace UNL::UAV::Events{
	class _API MessageReceivedEvent : public UNL::UAV::Event::Event{
	private:
		mavlink_message_t _message;
	public:
		MessageReceivedEvent(const mavlink_message_t& message) : _message(message){}
		inline const mavlink_message_t& getMessage() const {return _message;}
	};
}