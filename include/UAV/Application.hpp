#pragma once
#include "pch.hpp"
#include "Core.hpp"
#include "Serial.hpp"
#include "event/Dispatcher.hpp"
#include "common/mavlink.h"

namespace UNL::UAV{
class _API Application{
private:
	Serial _serial;
	Event::Dispatcher _readDispacher;
	Event::Dispatcher _commandDispatcher;
	bool _running = true;
	pthread_t _readThreadID;
	pthread_t _writeThreadID;
	pthread_t _heartbeatThreadID;

public:
	Application(const Serial& serial);

	void init();
	void update();

	void* readThread();
	void* writeThread();
	void* heartbeatThread();

	void addReadListener(Event::Listener& listener);
	void addCommand(Event::Listener& listener);

	void quitHandler( int sig );

	void writeMavlink(mavlink_message_t* msg);

	inline bool isRunning() const {return this->_running;};
	inline Event::Dispatcher& getCommandDispatcher(){return this->_commandDispatcher;}

	~Application();
};
};