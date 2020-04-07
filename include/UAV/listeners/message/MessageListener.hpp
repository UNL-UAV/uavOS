#pragma once
#include "../../Core.hpp"
#include "../../event/Listener.hpp"
#include "../../events/MessageReceivedEvent.hpp"
namespace UNL::UAV::Listener::Message{
	class _API MessageListener : public UNL::UAV::Event::Listener{
	protected:
		UNL::UAV::Events::MessageReceivedEvent* _event = nullptr;
	public:
		void onEvent(UNL::UAV::Event::Event* e) override;
	};
}