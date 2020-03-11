#pragma once
#include "../Core.hpp"
#include "pch.hpp"

namespace UNL::UAV::Event{
class _API Event{public:
	inline virtual bool handled() {return false;};
};
};