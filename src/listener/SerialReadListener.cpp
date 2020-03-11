#include "UAV/listeners/SerialReadListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/PacketReceivedEvent.hpp"
#include "UAV/Log.hpp"

namespace UNL::UAV::Listener{
void SerialReadListener::onEvent(UNL::UAV::Event::Event* e){
	UNL::UAV::Events::PacketReceivedEvent* PRE = static_cast<UNL::UAV::Events::PacketReceivedEvent*>(e);
	mavlink_message_t msg = PRE->getMessage();
 	switch(msg.msgid){
		case MAVLINK_MSG_ID_HEARTBEAT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HEARTBEAT" ); break;
		case MAVLINK_MSG_ID_SYS_STATUS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SYS_STATUS" ); break;
		case MAVLINK_MSG_ID_SYSTEM_TIME: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SYSTEM_TIME" ); break;
		case MAVLINK_MSG_ID_PING: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_PING" ); break;
		case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL" ); break;
		case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK" ); break;
		case MAVLINK_MSG_ID_AUTH_KEY: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_AUTH_KEY" ); break;
		case MAVLINK_MSG_ID_SET_MODE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_MODE" ); break;
		case MAVLINK_MSG_ID_PARAM_REQUEST_READ: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_PARAM_REQUEST_READ" ); break;
		case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_PARAM_REQUEST_LIST" ); break;
		case MAVLINK_MSG_ID_PARAM_VALUE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_PARAM_VALUE" ); break;
		case MAVLINK_MSG_ID_PARAM_SET: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_PARAM_SET" ); break;
		case MAVLINK_MSG_ID_GPS_RAW_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS_RAW_INT" ); break;
		case MAVLINK_MSG_ID_GPS_STATUS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS_STATUS" ); break;
		case MAVLINK_MSG_ID_SCALED_IMU: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SCALED_IMU" ); break;
		case MAVLINK_MSG_ID_RAW_IMU: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RAW_IMU" ); break;
		case MAVLINK_MSG_ID_RAW_PRESSURE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RAW_PRESSURE" ); break;
		case MAVLINK_MSG_ID_SCALED_PRESSURE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SCALED_PRESSURE" ); break;
		case MAVLINK_MSG_ID_ATTITUDE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ATTITUDE" ); break;
		case MAVLINK_MSG_ID_ATTITUDE_QUATERNION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ATTITUDE_QUATERNION" ); break;
		case MAVLINK_MSG_ID_LOCAL_POSITION_NED: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOCAL_POSITION_NED" ); break;
		case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GLOBAL_POSITION_INT" ); break;
		case MAVLINK_MSG_ID_RC_CHANNELS_SCALED: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RC_CHANNELS_SCALED" ); break;
		case MAVLINK_MSG_ID_RC_CHANNELS_RAW: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RC_CHANNELS_RAW" ); break;
		case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SERVO_OUTPUT_RAW" ); break;
		case MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST" ); break;
		case MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST" ); break;
		case MAVLINK_MSG_ID_MISSION_ITEM: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_ITEM" ); break;
		case MAVLINK_MSG_ID_MISSION_REQUEST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_REQUEST" ); break;
		case MAVLINK_MSG_ID_MISSION_SET_CURRENT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_SET_CURRENT" ); break;
		case MAVLINK_MSG_ID_MISSION_CURRENT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_CURRENT" ); break;
		case MAVLINK_MSG_ID_MISSION_REQUEST_LIST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_REQUEST_LIST" ); break;
		case MAVLINK_MSG_ID_MISSION_COUNT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_COUNT" ); break;
		case MAVLINK_MSG_ID_MISSION_CLEAR_ALL: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_CLEAR_ALL" ); break;
		case MAVLINK_MSG_ID_MISSION_ITEM_REACHED: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_ITEM_REACHED" ); break;
		case MAVLINK_MSG_ID_MISSION_ACK: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_ACK" ); break;
		case MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN" ); break;
		case MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN" ); break;
		case MAVLINK_MSG_ID_PARAM_MAP_RC: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_PARAM_MAP_RC" ); break;
		case MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA" ); break;
		case MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA" ); break;
		case MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV" ); break;
		case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT" ); break;
		case MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV" ); break;
		case MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV" ); break;
		case MAVLINK_MSG_ID_RC_CHANNELS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RC_CHANNELS" ); break;
		case MAVLINK_MSG_ID_REQUEST_DATA_STREAM: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_REQUEST_DATA_STREAM" ); break;
		case MAVLINK_MSG_ID_DATA_STREAM: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_DATA_STREAM" ); break;
		case MAVLINK_MSG_ID_MANUAL_CONTROL: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MANUAL_CONTROL" ); break;
		case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE" ); break;
		case MAVLINK_MSG_ID_MISSION_ITEM_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MISSION_ITEM_INT" ); break;
		case MAVLINK_MSG_ID_VFR_HUD: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_VFR_HUD" ); break;
		case MAVLINK_MSG_ID_COMMAND_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_COMMAND_INT" ); break;
		case MAVLINK_MSG_ID_COMMAND_LONG: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_COMMAND_LONG" ); break;
		case MAVLINK_MSG_ID_COMMAND_ACK: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_COMMAND_ACK" ); break;
		case MAVLINK_MSG_ID_MANUAL_SETPOINT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MANUAL_SETPOINT" ); break;
		case MAVLINK_MSG_ID_SET_ATTITUDE_TARGET: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_ATTITUDE_TARGET" ); break;
		case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED" ); break;
		case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED" ); break;
		case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT" ); break;
		case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT" ); break;
		case MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET" ); break;
		case MAVLINK_MSG_ID_HIL_STATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_STATE" ); break;
		case MAVLINK_MSG_ID_HIL_CONTROLS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_CONTROLS" ); break;
		case MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW" ); break;
		case MAVLINK_MSG_ID_OPTICAL_FLOW: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_OPTICAL_FLOW" ); break;
		case MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE" ); break;
		case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE" ); break;
		case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE" ); break;
		case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE" ); break;
		case MAVLINK_MSG_ID_HIGHRES_IMU: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIGHRES_IMU" ); break;
		case MAVLINK_MSG_ID_OPTICAL_FLOW_RAD: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_OPTICAL_FLOW_RAD" ); break;
		case MAVLINK_MSG_ID_HIL_SENSOR: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_SENSOR" ); break;
		case MAVLINK_MSG_ID_SIM_STATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SIM_STATE" ); break;
		case MAVLINK_MSG_ID_RADIO_STATUS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RADIO_STATUS" ); break;
		case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL" ); break;
		case MAVLINK_MSG_ID_TIMESYNC: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_TIMESYNC" ); break;
		case MAVLINK_MSG_ID_CAMERA_TRIGGER: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_CAMERA_TRIGGER" ); break;
		case MAVLINK_MSG_ID_HIL_GPS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_GPS" ); break;
		case MAVLINK_MSG_ID_HIL_OPTICAL_FLOW: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_OPTICAL_FLOW" ); break;
		case MAVLINK_MSG_ID_HIL_STATE_QUATERNION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HIL_STATE_QUATERNION" ); break;
		case MAVLINK_MSG_ID_SCALED_IMU2: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SCALED_IMU2" ); break;
		case MAVLINK_MSG_ID_LOG_REQUEST_LIST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOG_REQUEST_LIST" ); break;
		case MAVLINK_MSG_ID_LOG_ENTRY: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOG_ENTRY" ); break;
		case MAVLINK_MSG_ID_LOG_REQUEST_DATA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOG_REQUEST_DATA" ); break;
		case MAVLINK_MSG_ID_LOG_DATA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOG_DATA" ); break;
		case MAVLINK_MSG_ID_LOG_ERASE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOG_ERASE" ); break;
		case MAVLINK_MSG_ID_LOG_REQUEST_END: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LOG_REQUEST_END" ); break;
		case MAVLINK_MSG_ID_GPS_INJECT_DATA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS_INJECT_DATA" ); break;
		case MAVLINK_MSG_ID_GPS2_RAW: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS2_RAW" ); break;
		case MAVLINK_MSG_ID_POWER_STATUS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_POWER_STATUS" ); break;
		case MAVLINK_MSG_ID_SERIAL_CONTROL: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SERIAL_CONTROL" ); break;
		case MAVLINK_MSG_ID_GPS_RTK: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS_RTK" ); break;
		case MAVLINK_MSG_ID_GPS2_RTK: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_GPS2_RTK" ); break;
		case MAVLINK_MSG_ID_SCALED_IMU3: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SCALED_IMU3" ); break;
		case MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE" ); break;
		case MAVLINK_MSG_ID_ENCAPSULATED_DATA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ENCAPSULATED_DATA" ); break;
		case MAVLINK_MSG_ID_DISTANCE_SENSOR: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_DISTANCE_SENSOR" ); break;
		case MAVLINK_MSG_ID_TERRAIN_REQUEST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_TERRAIN_REQUEST" ); break;
		case MAVLINK_MSG_ID_TERRAIN_DATA: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_TERRAIN_DATA" ); break;
		case MAVLINK_MSG_ID_TERRAIN_CHECK: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_TERRAIN_CHECK" ); break;
		case MAVLINK_MSG_ID_TERRAIN_REPORT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_TERRAIN_REPORT" ); break;
		case MAVLINK_MSG_ID_SCALED_PRESSURE2: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SCALED_PRESSURE2" ); break;
		case MAVLINK_MSG_ID_ATT_POS_MOCAP: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ATT_POS_MOCAP" ); break;
		case MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET" ); break;
		case MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET" ); break;
		case MAVLINK_MSG_ID_ALTITUDE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ALTITUDE" ); break;
		case MAVLINK_MSG_ID_RESOURCE_REQUEST: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_RESOURCE_REQUEST" ); break;
		case MAVLINK_MSG_ID_SCALED_PRESSURE3: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SCALED_PRESSURE3" ); break;
		case MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE" ); break;
		case MAVLINK_MSG_ID_BATTERY_STATUS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_BATTERY_STATUS" ); break;
		case MAVLINK_MSG_ID_AUTOPILOT_VERSION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_AUTOPILOT_VERSION" ); break;
		case MAVLINK_MSG_ID_LANDING_TARGET: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_LANDING_TARGET" ); break;
		case MAVLINK_MSG_ID_FENCE_STATUS: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_FENCE_STATUS" ); break;
		case MAVLINK_MSG_ID_VIBRATION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_VIBRATION" ); break;
		case MAVLINK_MSG_ID_HOME_POSITION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_HOME_POSITION" ); break;
		case MAVLINK_MSG_ID_SET_HOME_POSITION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_SET_HOME_POSITION" ); break;
		case MAVLINK_MSG_ID_MESSAGE_INTERVAL: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MESSAGE_INTERVAL" ); break;
		case MAVLINK_MSG_ID_EXTENDED_SYS_STATE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_EXTENDED_SYS_STATE" ); break;
		case MAVLINK_MSG_ID_ADSB_VEHICLE: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_ADSB_VEHICLE" ); break;
		case MAVLINK_MSG_ID_V2_EXTENSION: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_V2_EXTENSION" ); break;
		case MAVLINK_MSG_ID_MEMORY_VECT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_MEMORY_VECT" ); break;
		case MAVLINK_MSG_ID_DEBUG_VECT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_DEBUG_VECT" ); break;
		case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_NAMED_VALUE_FLOAT" ); break;
		case MAVLINK_MSG_ID_NAMED_VALUE_INT: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_NAMED_VALUE_INT" ); break;
		case MAVLINK_MSG_ID_STATUSTEXT: 
			mavlink_statustext_t statusText;
			mavlink_msg_statustext_decode(&msg, &statusText);
			UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_STATUSTEXT" ); break;
			for(auto& i : statusText.text){
				UNL::UAV::Log::getLogger()->info(i);
			}
			break;
		case MAVLINK_MSG_ID_DEBUG: UNL::UAV::Log::getLogger()->info("MAVLINK_MSG_ID_DEBUG" ); break;
 		default: UNL::UAV::Log::getLogger()->info("UNKOWN" ); break;
 	}
}
}