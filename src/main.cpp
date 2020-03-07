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

//TODO: Dedicated Thread...
void readRunner(){
	std::cout << "Started Reader";
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

void mavWriter(mavlink_message_t* message){
	char buffer[300];
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buffer, message);
	int leng = serial.write(buffer, len);
	std::cout << "Written " << leng << std::endl;
}

int main(int argc, char** argv){
	signal(SIGINT,quit_handler);
	serial.start();
	std::cout << "Started Port" << std::endl;
	//readRunner();
    mavlink_message_t heartbeat;             //message holder
	mavlink_msg_heartbeat_pack(1, 250, &heartbeat, 2, 0, 128, 0, 7);
	mavWriter(&heartbeat);
	mavlink_message_t tune;
	mavlink_msg_play_tune_v2_pack(1, 250, &tune, 1, 1, 1, "l8 g a b g l16 g a b g");
	mavWriter(&tune);
	return 0;
}
