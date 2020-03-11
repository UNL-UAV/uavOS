#pragma once
#include "pch.hpp"
#include "../Core.hpp"
#include "Listener.hpp"
#include "Event.hpp"
namespace UNL::UAV::Event{
class _API Dispatcher{
private:
	std::vector<Listener*> _listeners;
public:
	inline void addListener(Listener* listener){ _listeners.push_back(listener); }
	void dispatch(Event* e);
	// inline void removeListenser(Listener* listener) const;
};
};