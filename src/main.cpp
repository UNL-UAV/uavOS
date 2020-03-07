#include "pch.hpp"
#include "UAV/uavOS.hpp"

void quit_handler( int sig ){
	
}

int main(int argc, char** argv){
	std::string port = "/dev/cu.usbmodem14201";
	UNL::UAV::Serial serial(port, 9600);
	signal(SIGINT,quit_handler);
	return 0;
}
