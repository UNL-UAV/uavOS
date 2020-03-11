#pragma once
#include "../Core.hpp"
#include "pch.hpp"

namespace UNL::UAV::Event{
class _API Event{
protected:
	bool _handled = false;
	inline virtual void handled(bool handled) {this->_handled = handled;};
public:
	inline virtual bool handled() {return _handled;};
};
};