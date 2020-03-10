#include "UAV/event/Dispatcher.hpp"

namespace UNL::UAV::Event{
void Dispatcher::dispatch(Event* e){
	for(Listener* listener : this->_listeners){
		listener->onEvent(e);
		HandledEvent* he = static_cast<HandledEvent*>(e);
		if(he->handled()){
			break;
		}
	}
}
};