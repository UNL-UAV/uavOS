#pragma once
#include "../event/Listener.hpp"
namespace UNL::UAV::Listener{
	class SerialReadListener : public UNL::UAV::Event::Listener{
	public:
		void onEvent(UNL::UAV::Event::Event* e) override;
	};
}