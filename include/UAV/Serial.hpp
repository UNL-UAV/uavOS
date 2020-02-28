#pragma once
#include "pch.hpp"
namespace UNL::UAV{
class Serial{
private:
	int _fd;
	pthread_mutex_t  _lock;
	std::string _uartName;
	int _status;
	int _baudrate;
public:
	Serial(std::string& path, int boardRate);
	~Serial();

	void start();
	void stop();
	void write(int len, char* buffer);
	void read(uint8_t& cp);
private:
};
}