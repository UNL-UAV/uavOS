#pragma once
#include "../../Core.hpp"
#include "../../event/Listener.hpp"
#include "CommandListener.hpp"
namespace UNL::UAV::Listener::Command{
	class _API ArmedListener : public CommandListener{
	public:
		void onEvent(UNL::UAV::Event::Event* event);
		void processCommand() override;
	};
}