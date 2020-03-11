#pragma once
#include "Core.hpp"
#include "pch.hpp"
namespace UNL::UAV{
class _API Serial{
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
	int write(char* buffer, int len);
	int read(uint8_t& cp);
private:
};
}