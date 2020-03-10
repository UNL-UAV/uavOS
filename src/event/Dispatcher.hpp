#include "UAV/event/Dispatcher.hpp"

namespace UNL::UAV::Event{
Dispatcher::dispatch(Event* e){
	for(Listener* listener : this->_listeners){
		listener->onEvent(e);
		if(HandledEvent* he = dynamic_cast<HandledEvent*>(e) && he->handled()){
			break;
		}
	}
}
};