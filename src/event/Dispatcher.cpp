#include "UAV/event/Dispatcher.hpp"
#include "UAV/Log.hpp"
namespace UNL::UAV::Event{
void Dispatcher::dispatch(Event* e){
	for(auto& listener : this->_listeners){
		listener->onEvent(e);
		if(e->handled()){
			break;
		}
	}
}
};