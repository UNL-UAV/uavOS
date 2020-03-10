#pragma once
#include "pch.hpp"

namespace UNL::UAV::Event{
class Event{};
class HandledEvent : public Event{
public:
	virtual bool handled() = 0;
};
};