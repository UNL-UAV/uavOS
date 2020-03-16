#pragma once
#include "../Core.hpp"
#include "../event/Listener.hpp"
namespace UNL::UAV::Listener{
	class _API StatusTextListener : public UNL::UAV::Event::Listener{
	public:
		void onEvent(UNL::UAV::Event::Event* e) override;
	};
}