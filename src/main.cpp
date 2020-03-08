#include "pch.hpp"
#include "UAV/uavOS.hpp"
#include "common/mavlink.h"
#include <pthread.h>

static std::thread readThread;
static std::string port = "/dev/cu.usbmodem14101";
static UNL::UAV::Serial serial(port, 57600);
static bool running = true;
static pthread_t readThreadID;
static pthread_t writeThreadID;
static int heartbeats = 0;

void quit_handler( int sig ){
	std::cout << "Received " << sig << std::endl;
	std::cout << heartbeats << " heartbeats" << std::endl;
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
			 	std::cout << "Read> ";
			 	switch(msg.msgid){
			 		case MAVLINK_MSG_ID_HEARTBEAT: std::cout << "MAVLINK_MSG_ID_HEARTBEAT" << std::endl; heartbeats++; break;
case MAVLINK_MSG_ID_SYS_STATUS: std::cout << "MAVLINK_MSG_ID_SYS_STATUS" << std::endl; break;
case MAVLINK_MSG_ID_SYSTEM_TIME: std::cout << "MAVLINK_MSG_ID_SYSTEM_TIME" << std::endl; break;
case MAVLINK_MSG_ID_PING: std::cout << "MAVLINK_MSG_ID_PING" << std::endl; break;
case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL: std::cout << "MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL" << std::endl; break;
case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK: std::cout << "MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK" << std::endl; break;
case MAVLINK_MSG_ID_AUTH_KEY: std::cout << "MAVLINK_MSG_ID_AUTH_KEY" << std::endl; break;
case MAVLINK_MSG_ID_SET_MODE: std::cout << "MAVLINK_MSG_ID_SET_MODE" << std::endl; break;
case MAVLINK_MSG_ID_PARAM_REQUEST_READ: std::cout << "MAVLINK_MSG_ID_PARAM_REQUEST_READ" << std::endl; break;
case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: std::cout << "MAVLINK_MSG_ID_PARAM_REQUEST_LIST" << std::endl; break;
case MAVLINK_MSG_ID_PARAM_VALUE: std::cout << "MAVLINK_MSG_ID_PARAM_VALUE" << std::endl; break;
case MAVLINK_MSG_ID_PARAM_SET: std::cout << "MAVLINK_MSG_ID_PARAM_SET" << std::endl; break;
case MAVLINK_MSG_ID_GPS_RAW_INT: std::cout << "MAVLINK_MSG_ID_GPS_RAW_INT" << std::endl; break;
case MAVLINK_MSG_ID_GPS_STATUS: std::cout << "MAVLINK_MSG_ID_GPS_STATUS" << std::endl; break;
case MAVLINK_MSG_ID_SCALED_IMU: std::cout << "MAVLINK_MSG_ID_SCALED_IMU" << std::endl; break;
case MAVLINK_MSG_ID_RAW_IMU: std::cout << "MAVLINK_MSG_ID_RAW_IMU" << std::endl; break;
case MAVLINK_MSG_ID_RAW_PRESSURE: std::cout << "MAVLINK_MSG_ID_RAW_PRESSURE" << std::endl; break;
case MAVLINK_MSG_ID_SCALED_PRESSURE: std::cout << "MAVLINK_MSG_ID_SCALED_PRESSURE" << std::endl; break;
case MAVLINK_MSG_ID_ATTITUDE: std::cout << "MAVLINK_MSG_ID_ATTITUDE" << std::endl; break;
case MAVLINK_MSG_ID_ATTITUDE_QUATERNION: std::cout << "MAVLINK_MSG_ID_ATTITUDE_QUATERNION" << std::endl; break;
case MAVLINK_MSG_ID_LOCAL_POSITION_NED: std::cout << "MAVLINK_MSG_ID_LOCAL_POSITION_NED" << std::endl; break;
case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: std::cout << "MAVLINK_MSG_ID_GLOBAL_POSITION_INT" << std::endl; break;
case MAVLINK_MSG_ID_RC_CHANNELS_SCALED: std::cout << "MAVLINK_MSG_ID_RC_CHANNELS_SCALED" << std::endl; break;
case MAVLINK_MSG_ID_RC_CHANNELS_RAW: std::cout << "MAVLINK_MSG_ID_RC_CHANNELS_RAW" << std::endl; break;
case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW: std::cout << "MAVLINK_MSG_ID_SERVO_OUTPUT_RAW" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST: std::cout << "MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST: std::cout << "MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_ITEM: std::cout << "MAVLINK_MSG_ID_MISSION_ITEM" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_REQUEST: std::cout << "MAVLINK_MSG_ID_MISSION_REQUEST" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_SET_CURRENT: std::cout << "MAVLINK_MSG_ID_MISSION_SET_CURRENT" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_CURRENT: std::cout << "MAVLINK_MSG_ID_MISSION_CURRENT" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_REQUEST_LIST: std::cout << "MAVLINK_MSG_ID_MISSION_REQUEST_LIST" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_COUNT: std::cout << "MAVLINK_MSG_ID_MISSION_COUNT" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_CLEAR_ALL: std::cout << "MAVLINK_MSG_ID_MISSION_CLEAR_ALL" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_ITEM_REACHED: std::cout << "MAVLINK_MSG_ID_MISSION_ITEM_REACHED" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_ACK: std::cout << "MAVLINK_MSG_ID_MISSION_ACK" << std::endl; break;
case MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN: std::cout << "MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN" << std::endl; break;
case MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN: std::cout << "MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN" << std::endl; break;
case MAVLINK_MSG_ID_PARAM_MAP_RC: std::cout << "MAVLINK_MSG_ID_PARAM_MAP_RC" << std::endl; break;
case MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA: std::cout << "MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA" << std::endl; break;
case MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA: std::cout << "MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA" << std::endl; break;
case MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV: std::cout << "MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV" << std::endl; break;
case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT: std::cout << "MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT" << std::endl; break;
case MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV: std::cout << "MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV" << std::endl; break;
case MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV: std::cout << "MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV" << std::endl; break;
case MAVLINK_MSG_ID_RC_CHANNELS: std::cout << "MAVLINK_MSG_ID_RC_CHANNELS" << std::endl; break;
case MAVLINK_MSG_ID_REQUEST_DATA_STREAM: std::cout << "MAVLINK_MSG_ID_REQUEST_DATA_STREAM" << std::endl; break;
case MAVLINK_MSG_ID_DATA_STREAM: std::cout << "MAVLINK_MSG_ID_DATA_STREAM" << std::endl; break;
case MAVLINK_MSG_ID_MANUAL_CONTROL: std::cout << "MAVLINK_MSG_ID_MANUAL_CONTROL" << std::endl; break;
case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE: std::cout << "MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE" << std::endl; break;
case MAVLINK_MSG_ID_MISSION_ITEM_INT: std::cout << "MAVLINK_MSG_ID_MISSION_ITEM_INT" << std::endl; break;
case MAVLINK_MSG_ID_VFR_HUD: std::cout << "MAVLINK_MSG_ID_VFR_HUD" << std::endl; break;
case MAVLINK_MSG_ID_COMMAND_INT: std::cout << "MAVLINK_MSG_ID_COMMAND_INT" << std::endl; break;
case MAVLINK_MSG_ID_COMMAND_LONG: std::cout << "MAVLINK_MSG_ID_COMMAND_LONG" << std::endl; break;
case MAVLINK_MSG_ID_COMMAND_ACK: std::cout << "MAVLINK_MSG_ID_COMMAND_ACK" << std::endl; break;
case MAVLINK_MSG_ID_MANUAL_SETPOINT: std::cout << "MAVLINK_MSG_ID_MANUAL_SETPOINT" << std::endl; break;
case MAVLINK_MSG_ID_SET_ATTITUDE_TARGET: std::cout << "MAVLINK_MSG_ID_SET_ATTITUDE_TARGET" << std::endl; break;
case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED: std::cout << "MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED" << std::endl; break;
case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED: std::cout << "MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED" << std::endl; break;
case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT: std::cout << "MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT" << std::endl; break;
case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT: std::cout << "MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT" << std::endl; break;
case MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET: std::cout << "MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET" << std::endl; break;
case MAVLINK_MSG_ID_HIL_STATE: std::cout << "MAVLINK_MSG_ID_HIL_STATE" << std::endl; break;
case MAVLINK_MSG_ID_HIL_CONTROLS: std::cout << "MAVLINK_MSG_ID_HIL_CONTROLS" << std::endl; break;
case MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW: std::cout << "MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW" << std::endl; break;
case MAVLINK_MSG_ID_OPTICAL_FLOW: std::cout << "MAVLINK_MSG_ID_OPTICAL_FLOW" << std::endl; break;
case MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE: std::cout << "MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE" << std::endl; break;
case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE: std::cout << "MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE" << std::endl; break;
case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE: std::cout << "MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE" << std::endl; break;
case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE: std::cout << "MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE" << std::endl; break;
case MAVLINK_MSG_ID_HIGHRES_IMU: std::cout << "MAVLINK_MSG_ID_HIGHRES_IMU" << std::endl; break;
case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD: std::cout << "MAVLINK_MSG_ID_OPTICAL_FLOW_RAD" << std::endl; break;
case MAVLINK_MSG_ID_HIL_SENSOR: std::cout << "MAVLINK_MSG_ID_HIL_SENSOR" << std::endl; break;
case MAVLINK_MSG_ID_SIM_STATE: std::cout << "MAVLINK_MSG_ID_SIM_STATE" << std::endl; break;
case MAVLINK_MSG_ID_RADIO_STATUS: std::cout << "MAVLINK_MSG_ID_RADIO_STATUS" << std::endl; break;
case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: std::cout << "MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL" << std::endl; break;
case MAVLINK_MSG_ID_TIMESYNC: std::cout << "MAVLINK_MSG_ID_TIMESYNC" << std::endl; break;
case MAVLINK_MSG_ID_CAMERA_TRIGGER: std::cout << "MAVLINK_MSG_ID_CAMERA_TRIGGER" << std::endl; break;
case MAVLINK_MSG_ID_HIL_GPS: std::cout << "MAVLINK_MSG_ID_HIL_GPS" << std::endl; break;
case MAVLINK_MSG_ID_HIL_OPTICAL_FLOW: std::cout << "MAVLINK_MSG_ID_HIL_OPTICAL_FLOW" << std::endl; break;
case MAVLINK_MSG_ID_HIL_STATE_QUATERNION: std::cout << "MAVLINK_MSG_ID_HIL_STATE_QUATERNION" << std::endl; break;
case MAVLINK_MSG_ID_SCALED_IMU2: std::cout << "MAVLINK_MSG_ID_SCALED_IMU2" << std::endl; break;
case MAVLINK_MSG_ID_LOG_REQUEST_LIST: std::cout << "MAVLINK_MSG_ID_LOG_REQUEST_LIST" << std::endl; break;
case MAVLINK_MSG_ID_LOG_ENTRY: std::cout << "MAVLINK_MSG_ID_LOG_ENTRY" << std::endl; break;
case MAVLINK_MSG_ID_LOG_REQUEST_DATA: std::cout << "MAVLINK_MSG_ID_LOG_REQUEST_DATA" << std::endl; break;
case MAVLINK_MSG_ID_LOG_DATA: std::cout << "MAVLINK_MSG_ID_LOG_DATA" << std::endl; break;
case MAVLINK_MSG_ID_LOG_ERASE: std::cout << "MAVLINK_MSG_ID_LOG_ERASE" << std::endl; break;
case MAVLINK_MSG_ID_LOG_REQUEST_END: std::cout << "MAVLINK_MSG_ID_LOG_REQUEST_END" << std::endl; break;
case MAVLINK_MSG_ID_GPS_INJECT_DATA: std::cout << "MAVLINK_MSG_ID_GPS_INJECT_DATA" << std::endl; break;
case MAVLINK_MSG_ID_GPS2_RAW: std::cout << "MAVLINK_MSG_ID_GPS2_RAW" << std::endl; break;
case MAVLINK_MSG_ID_POWER_STATUS: std::cout << "MAVLINK_MSG_ID_POWER_STATUS" << std::endl; break;
case MAVLINK_MSG_ID_SERIAL_CONTROL: std::cout << "MAVLINK_MSG_ID_SERIAL_CONTROL" << std::endl; break;
case MAVLINK_MSG_ID_GPS_RTK: std::cout << "MAVLINK_MSG_ID_GPS_RTK" << std::endl; break;
case MAVLINK_MSG_ID_GPS2_RTK: std::cout << "MAVLINK_MSG_ID_GPS2_RTK" << std::endl; break;
case MAVLINK_MSG_ID_SCALED_IMU3: std::cout << "MAVLINK_MSG_ID_SCALED_IMU3" << std::endl; break;
case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE: std::cout << "MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE" << std::endl; break;
case MAVLINK_MSG_ID_ENCAPSULATED_DATA: std::cout << "MAVLINK_MSG_ID_ENCAPSULATED_DATA" << std::endl; break;
case MAVLINK_MSG_ID_DISTANCE_SENSOR: std::cout << "MAVLINK_MSG_ID_DISTANCE_SENSOR" << std::endl; break;
case MAVLINK_MSG_ID_TERRAIN_REQUEST: std::cout << "MAVLINK_MSG_ID_TERRAIN_REQUEST" << std::endl; break;
case MAVLINK_MSG_ID_TERRAIN_DATA: std::cout << "MAVLINK_MSG_ID_TERRAIN_DATA" << std::endl; break;
case MAVLINK_MSG_ID_TERRAIN_CHECK: std::cout << "MAVLINK_MSG_ID_TERRAIN_CHECK" << std::endl; break;
case MAVLINK_MSG_ID_TERRAIN_REPORT: std::cout << "MAVLINK_MSG_ID_TERRAIN_REPORT" << std::endl; break;
case MAVLINK_MSG_ID_SCALED_PRESSURE2: std::cout << "MAVLINK_MSG_ID_SCALED_PRESSURE2" << std::endl; break;
case MAVLINK_MSG_ID_ATT_POS_MOCAP: std::cout << "MAVLINK_MSG_ID_ATT_POS_MOCAP" << std::endl; break;
case MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET: std::cout << "MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET" << std::endl; break;
case MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET: std::cout << "MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET" << std::endl; break;
case MAVLINK_MSG_ID_ALTITUDE: std::cout << "MAVLINK_MSG_ID_ALTITUDE" << std::endl; break;
case MAVLINK_MSG_ID_RESOURCE_REQUEST: std::cout << "MAVLINK_MSG_ID_RESOURCE_REQUEST" << std::endl; break;
case MAVLINK_MSG_ID_SCALED_PRESSURE3: std::cout << "MAVLINK_MSG_ID_SCALED_PRESSURE3" << std::endl; break;
case MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE: std::cout << "MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE" << std::endl; break;
case MAVLINK_MSG_ID_BATTERY_STATUS: std::cout << "MAVLINK_MSG_ID_BATTERY_STATUS" << std::endl; break;
case MAVLINK_MSG_ID_AUTOPILOT_VERSION: std::cout << "MAVLINK_MSG_ID_AUTOPILOT_VERSION" << std::endl; break;
case MAVLINK_MSG_ID_LANDING_TARGET: std::cout << "MAVLINK_MSG_ID_LANDING_TARGET" << std::endl; break;
case MAVLINK_MSG_ID_FENCE_STATUS: std::cout << "MAVLINK_MSG_ID_FENCE_STATUS" << std::endl; break;
case MAVLINK_MSG_ID_VIBRATION: std::cout << "MAVLINK_MSG_ID_VIBRATION" << std::endl; break;
case MAVLINK_MSG_ID_HOME_POSITION: std::cout << "MAVLINK_MSG_ID_HOME_POSITION" << std::endl; break;
case MAVLINK_MSG_ID_SET_HOME_POSITION: std::cout << "MAVLINK_MSG_ID_SET_HOME_POSITION" << std::endl; break;
case MAVLINK_MSG_ID_MESSAGE_INTERVAL: std::cout << "MAVLINK_MSG_ID_MESSAGE_INTERVAL" << std::endl; break;
case MAVLINK_MSG_ID_EXTENDED_SYS_STATE: std::cout << "MAVLINK_MSG_ID_EXTENDED_SYS_STATE" << std::endl; break;
case MAVLINK_MSG_ID_ADSB_VEHICLE: std::cout << "MAVLINK_MSG_ID_ADSB_VEHICLE" << std::endl; break;
case MAVLINK_MSG_ID_V2_EXTENSION: std::cout << "MAVLINK_MSG_ID_V2_EXTENSION" << std::endl; break;
case MAVLINK_MSG_ID_MEMORY_VECT: std::cout << "MAVLINK_MSG_ID_MEMORY_VECT" << std::endl; break;
case MAVLINK_MSG_ID_DEBUG_VECT: std::cout << "MAVLINK_MSG_ID_DEBUG_VECT" << std::endl; break;
case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT: std::cout << "MAVLINK_MSG_ID_NAMED_VALUE_FLOAT" << std::endl; break;
case MAVLINK_MSG_ID_NAMED_VALUE_INT: std::cout << "MAVLINK_MSG_ID_NAMED_VALUE_INT" << std::endl; break;
case MAVLINK_MSG_ID_STATUSTEXT: 
	mavlink_statustext_t statusText;
	mavlink_msg_statustext_decode(&msg, &statusText);
	std::cout << "MAVLINK_MSG_ID_STATUSTEXT" << std::endl; break;
	for(auto& i : statusText.text){
		std::cout << i;
	}
	std::cout << std::endl;
case MAVLINK_MSG_ID_DEBUG: std::cout << "MAVLINK_MSG_ID_DEBUG" << std::endl; break;
			 	default: std::cout << "UNKOWN" << std::endl; break;
			 	}
			}
		}
	}
	::pthread_exit(NULL);
}

void mavWriter(mavlink_message_t* message){
	char buffer[300];
	unsigned len = mavlink_msg_to_send_buffer((uint8_t*)buffer, message);
	int leng = serial.write(buffer, len);
	std::cout << "Write> ID:" << message->msgid << " Write Length: " << leng << " bufferLength: "<< len << std::endl;
}

void offBoard(bool flag){
	mavlink_msg_set_mode_pack(
			250, 	// @param system_id ID of this system
			1,	// @param component_id ID of this component (e.g. 200 for IMU)
			&msg, 			// @param msg The MAVLink message to compress the data into
			targetSysId, 		// @param target_system The system setting the mode
			1, 			// @param base_mode The new base mode (Should be 1 to use custom_mode)
			mode);			// @param custom_mode The new autopilot-specific mode. Defined in ArduCopter/defines.h
	mavlink_message_t offBoard;
	mavlink_msg_command_int_pack(250, 1, &offBoard, 1, 0, MAV_FRAME_LOCAL_NED, MAV_CMD_DO_GUIDED_MASTER, 1, 0,
    250, 250, 0, 0, 0, 0, 0);
	mavWriter(&offBoard);

    mavlink_msg_command_int_pack(250, 250, &offBoard, 1, 0, MAV_FRAME_LOCAL_NED, MAV_CMD_NAV_GUIDED_ENABLE,
    1, 0, 1, 0, 0, 0, 0, 0, 0);
	mavWriter(&offBoard);
}

void writeHeartbeat(){
	offBoard(true);
	mavlink_message_t heartbeat;             //message holder
	mavlink_msg_heartbeat_pack(1, 250, &heartbeat, 2, 0, 128, 0, 7);
	mavWriter(&heartbeat);
	mavlink_message_t tune;
	mavlink_msg_play_tune_v2_pack(1, 250, &tune, 1, 1, 1, "l8 g a b g l16 g a b g");
	mavWriter(&tune);
	mavlink_message_t throttle;
	mavlink_msg_command_int_pack(250, 250, &throttle, 1, 1, MAV_FRAME_LOCAL_NED, MAV_CMD_DO_CHANGE_SPEED, 1, 0,
    2, 1, 1, 1, 0, 0, 0);
	mavWriter(&throttle);
	offBoard(false);
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
