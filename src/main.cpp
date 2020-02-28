#include "pch.hpp"
#include "UAV/uavOS.hpp"
int main(int argc, char** argv){
	std::string port = "/dev/null";
	UNL::UAV::Serial serial(port, 9600);
	serial.start();
	char* buffer = "Hello World";
	serial.write(11, buffer);
	uint8_t cp;
	serial.read(cp);
	serial.stop();
	return 0;
}
