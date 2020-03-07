#include "pch.hpp"
#include "UAV/uavOS.hpp"
#include "common/mavlink.h"
#include <pthread.h>

static std::thread readThread;
static std::string port = "/dev/cu.usbmodem01";
static UNL::UAV::Serial serial(port, 57600);
static bool running = true;
static pthread_t readThreadID;

void quit_handler( int sig ){
	std::cout << "Received " << sig << std::endl;
	running = false;
	serial.stop();
}

void readRunner(){
	uint8_t hasDecoded =0;
	mavlink_message_t msg;
	mavlink_status_t status;

	while(running){
		uint8_t cp;
		int res = serial.read(cp);
		if(res){
			std::cout << "read: " << cp;
			hasDecoded = mavlink_parse_char(MAVLINK_COMM_1, cp, &msg, &status);
			if(hasDecoded){
				std::cout << std::endl;
			 	std::cout << "Decoded" << std::endl;
			 	std::cout << msg.msgid << std::endl;
			}
		}
	}
}

int main(int argc, char** argv){
	signal(SIGINT,quit_handler);
	serial.start();
	std::cout << "Started Port" << std::endl;
	readRunner();
	return 0;
}
