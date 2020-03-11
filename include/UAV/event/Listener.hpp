#pragma once
#include "../Core.hpp"
#include "Event.hpp"
namespace UNL::UAV::Event{
class _API Listener{
public:
	virtual void onEvent(Event* e) = 0;
	virtual ~Listener() = default;
};
};