#pragma once
#include "pch.hpp"
#include "Serial.hpp"
#include "event/Dispatcher.hpp"
#include "common/mavlink.h"

namespace UNL::UAV{
class Application{
private:
	Serial _serial;
	Event::Dispatcher _readDispacher;
	bool _running = true;
	pthread_t _readThreadID;
	pthread_t _writeThreadID;
public:
	Application(const Serial& serial);

	void init();

	void* readThread();
	void* writeThread();

	void addReadListener(Event::Listener& listener);
	void quitHandler( int sig );

	void mavWriter(mavlink_message_t* msg);

	inline bool isRunning() const {return this->_running;}

	~Application();
};
};