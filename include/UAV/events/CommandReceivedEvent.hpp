#pragma once
#include "../Core.hpp"
#include "pch.hpp"
#include "../event/Event.hpp"
#include "../Serial.hpp"
#include "common/mavlink.h"

namespace UNL::UAV::Events{
	class _API CommandReceivedEvent : public UNL::UAV::Event::Event{
	private:
		std::string _command;
		UNL::UAV::Serial _serial;
	public:
		CommandReceivedEvent(const UNL::UAV::Serial& serial, std::string& command) : _command(command), _serial(serial){}
		inline const std::string& getCommandString() const {return _command;};
		inline const UNL::UAV::Serial getSerial() const {return _serial;}
	};
}