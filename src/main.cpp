#include "pch.hpp"
#include "UAV/uavOS.hpp"
#include "common/mavlink.h"
#include <pthread.h>

static std::thread readThread;
static std::string port = "/dev/cu.usbmodem01";
static UNL::UAV::Serial serial(port, 57600);
static bool running = true;
static pthread_t readThreadID;
static pthread_t writeThreadID;

void quit_handler( int sig ){
	std::cout << "Received " << sig << std::endl;
	running = false;
	::pthread_join(readThreadID, NULL);
	::pthread_join(writeThreadID, NULL);
	serial.stop();
}

//TODO: Dedicated Thread...
void* readRunner(void* arg){
	uint8_t hasDecoded =0;
	mavlink_message_t msg;
	mavlink_status_t status;

	while(running){
		uint8_t cp;
		int res = serial.read(cp);
		if(res){
			hasDecoded = mavlink_parse_char(MAVLINK_COMM_1, cp, &msg, &status);
			if(hasDecoded){
				std::cout << std::endl;
			 	std::cout << "Decoded" << std::endl;
			 	std::cout << msg.msgid << std::endl;
			}
		}
	}
	::pthread_exit(NULL);
}

void mavWriter(mavlink_message_t* message){
	char buffer[300];
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buffer, message);
	int leng = serial.write(buffer, len);
	std::cout << "Written " << leng << std::endl;
}

void writeHeartbeat(){
	mavlink_message_t heartbeat;             //message holder
	mavlink_msg_heartbeat_pack(1, 255, &heartbeat, 2, 0, 128, 0, 7);
	mavWriter(&heartbeat);
	std::cout << "Sent Heartbeat" << std::endl;
}

void* writeRunner(void* test){
	writeHeartbeat();
	::pthread_exit(NULL);
}

int main(int argc, char** argv){
	signal(SIGINT,quit_handler);
	serial.start();
	std::cout << "Started Port" << std::endl;

	std::cout << "Starting Reader Thread";
	::pthread_create(&readThreadID, NULL, &readRunner, NULL);

	std::cout << "Writing Started Thread";
	::pthread_create(&writeThreadID, NULL, &writeRunner, NULL);

	while (running);
	return 0;
}
