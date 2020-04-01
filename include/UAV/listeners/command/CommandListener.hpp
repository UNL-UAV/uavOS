#pragma once
#include "../../Core.hpp"
#include "../../event/Listener.hpp"
#include "../../events/CommandReceivedEvent.hpp"
namespace UNL::UAV::Listener::Command{
	class _API CommandListener : public UNL::UAV::Event::Listener{
	protected:
		UNL::UAV::Events::CommandReceivedEvent* _event = nullptr;
	public:
		void onEvent(UNL::UAV::Event::Event* e) override;
		virtual void processCommand() = 0;
	};
}