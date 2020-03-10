#pragma once
#include "Event.hpp"
namespace UNL::UAV::Event{
class Listener{
public:
	virtual void onEvent(Event* e) = 0;
};
};