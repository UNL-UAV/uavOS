#include "UAV/Application.hpp"
#include "UAV/events/PacketReceivedEvent.hpp"
#include "UAV/Log.hpp"
#include "UAV/events/CommandReceivedEvent.hpp"
#include "UAV/events/MessageReceivedEvent.hpp"

namespace UNL::UAV{
Application::Application(const Serial& serial): _serial(serial){

}

//outputs to the log, initilization debugging messages
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
	
	UNL::UAV::Log::getLogger()->info("Starting Heartbeat Thread");
	::pthread_create(&(this->_heartbeatThreadID), NULL, [](void* self) -> void* {
		return static_cast<Application*>(self)->heartbeatThread();
	}, this);
}

void Application::addReadListener(UNL::UAV::Event::Listener& listener){
	this->_readDispacher.addListener(&listener);
}

void Application::addCommand(UNL::UAV::Event::Listener& listener){
	this->_commandDispatcher.addListener(&listener);
}

void* Application::readThread(){
	uint8_t hasDecoded =0;
	mavlink_message_t msg;
	mavlink_status_t status;
	mavlink_attitude_t attitude;
	mavlink_heartbeat_t heartbeat;

	while(_running){
		uint8_t cp;
		int res = _serial.read(cp);
		if(res){
			hasDecoded = mavlink_parse_char(MAVLINK_COMM_1, cp, &msg, &status);
			if(hasDecoded){
				Events::PacketReceivedEvent event = Events::PacketReceivedEvent(this->_serial, msg);
				this->_readDispacher.dispatch(&event);
				Events::MessageReceivedEvent MSGevent = Events::MessageReceivedEvent(msg);
			}
		}
	}
	::pthread_exit(NULL);
}

void* Application::writeThread(){
	//TODO: make a queue and send out messages
	::pthread_exit(NULL);
}

void* Application::heartbeatThread(){
	using namespace std::literals::chrono_literals;
	auto last = std::chrono::high_resolution_clock::now();
	while(_running){
		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> time =  now - last;
		if(time.count() > 1.0f){
			mavlink_message_t message;
			mavlink_heartbeat_t heartbeat;

			//Ground control station type
			heartbeat.type = MAV_TYPE_GCS;

			mavlink_msg_heartbeat_encode(0xFF, 0xBE, &message, &heartbeat);
			
			//SEND
			this->writeMavlink(&message);

			last = std::chrono::high_resolution_clock::now();
		}
	}
	::pthread_exit(NULL);
}

void Application::update(){
	std::string str;
	getline(std::cin, str);
	UNL::UAV::Events::CommandReceivedEvent cre = UNL::UAV::Events::CommandReceivedEvent(_serial, str);
	this->_commandDispatcher.dispatch(&cre);
}

void Application::quitHandler(int sig){
	UNL::UAV::Log::getLogger()->info(std::string("Received ")+std::to_string(sig));
	this->_running = false;
	::pthread_join(this->_readThreadID, nullptr);
	::pthread_join(this->_writeThreadID, nullptr);
	::pthread_join(this->_heartbeatThreadID, nullptr);
	_serial.stop();
}

void Application::writeMavlink(mavlink_message_t* message){
	char buffer[300];
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buffer, message);
	int leng = _serial.write(buffer, len);
	UNL::UAV::Log::getWriter()->info(message->msgid);
}

Application::~Application(){
	this->quitHandler(0);
}
};