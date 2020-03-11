#include "UAV/Application.hpp"
#include "UAV/events/PacketReceivedEvent.hpp"
#include "UAV/Log.hpp"
namespace UNL::UAV{
Application::Application(const Serial& serial): _serial(serial){

}

void Application::init(){
	this->_serial.start();
	UNL::UAV::Log::getLogger()->info("Starting Read Thread");
	::pthread_create(&(this->_readThreadID), NULL, [](void* self) -> void* {
		return static_cast<Application*>(self)->readThread();
	}, this);
	UNL::UAV::Log::getLogger()->info("Starting Write Thread");
	::pthread_create(&(this->_writeThreadID), NULL, [](void* self) -> void* {
		return static_cast<Application*>(self)->writeThread();
	}, this);
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
				Events::PacketReceivedEvent event = Events::PacketReceivedEvent(msg);
				this->_readDispacher.dispatch(&event);
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
	UNL::UAV::Log::getLogger()->info(std::string("Received ")+std::to_string(sig));
	this->_running = false;
	::pthread_join(_readThreadID, nullptr);
	::pthread_join(_writeThreadID, nullptr);
	_serial.stop();
}

void Application::mavWriter(mavlink_message_t* message){
	char buffer[300];
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buffer, message);
	int leng = _serial.write(buffer, len);
	UNL::UAV::Log::getLogger()->info(std::string("Write> ID:")+std::to_string(message->msgid)+std::string(" Write Length: ")+ std::to_string(leng) + std::string(" bufferLength: ")+ std::to_string(len));
}

Application::~Application(){
	this->quitHandler(-1);
}
};