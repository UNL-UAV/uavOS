#include "UAV/Application.hpp"
#include "UAV/events/PacketReceivedEvent.hpp"
namespace UNL::UAV{
Application::Application(const Serial& serial): _serial(serial){

}

void Application::init(){
	this->_serial.start();
	::pthread_create(&(this->_readThreadID), NULL, (void*) &(Application::readThread), this);
	::pthread_create(&(this->_writeThreadID), NULL, (void*) &(Application::writeThread), this);
}

void Application::addReadListener(UNL::UAV::Event::Listener& listener){
	this->_readDispacher.addListener(&listener);
}

void* Application::readThread(){
	uint8_t hasDecoded =0;
	mavlink_message_t msg;
	mavlink_status_t status;

	while(_running){
		uint8_t cp;
		int res = _serial.read(cp);
		if(res){
			hasDecoded = mavlink_parse_char(MAVLINK_COMM_1, cp, &msg, &status);
			if(hasDecoded){
				Events::PacketReceivedEvent* event = new Events::PacketReceivedEvent(msg);
				this->_readDispacher.dispatch(event);

				//Clean up if not memory leak.
				delete event;
			}
		}
	}
	::pthread_exit(NULL);
}

void* Application::writeThread(){
	//TODO: make a queue and send out messages
	::pthread_exit(NULL);
}

void Application::quitHandler(int sig){
	std::cout << "Received " << sig << std::endl;
	this->_running = false;
	::pthread_join(_readThreadID, NULL);
	::pthread_join(_writeThreadID, NULL);
	_serial.stop();
}

void Application::mavWriter(mavlink_message_t* message){
	char buffer[300];
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buffer, message);
	int leng = _serial.write(buffer, len);
	std::cout << "Write> ID:" << message->msgid << " Write Length: " << leng << " bufferLength: "<< len << std::endl;
}

Application::~Application(){
	this->quitHandler(-1);
}
};