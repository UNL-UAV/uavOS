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
    char tune [4] = {'a', 'b', 'c', 'd'};   //play this tune
    char tune2 [4] = {'a', 'b', 'c', 'd'};  //play this tune extenstion
    mavlink_message_t playTune;             //message holder
    mavlink_msg_play_tune_pack(1, 255, &playTune, 1, 255, tune, tune2); //write the message into the mavlink format
	mavWriter(&playTune);                     //attempt to write to the serail
	serial.stop();
	return 0;
}
