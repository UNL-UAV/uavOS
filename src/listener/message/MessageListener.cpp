#include "UAV/listeners/message/MessageListener.hpp"
#include "common/mavlink.h"
#include "UAV/events/MessageReceivedEvent.hpp"
#include "UAV/Log.hpp"


class Drone {

    mavlink_attitude_t attitude;
    mavlink_heartbeat_t heartbeat;
    mavlink_vfr_hud_t headupDisplay;

    public:

    void updateAttitude(mavlink_message_t msg){
        mavlink_msg_attitude_decode(&msg, &this->attitude);
    }
    void updateHeartbeat(mavlink_message_t msg){
        mavlink_msg_heartbeat_decode(&msg, &this->heartbeat);
    }
    void updateHeadupDisplay(mavlink_message_t msg){
        mavlink_msg_vfr_hud_decode(&msg, &this->headupDisplay);
    }
};

namespace UNL::UAV::Listener::Message{
    void MessageListener::onEvent(UNL::UAV::Event::Event* e){
        UNL::UAV::Events::MessageReceivedEvent* MRE = static_cast<UNL::UAV::Events::MessageReceivedEvent*>(e);
        mavlink_message_t msg = MRE->getMessage();
        Drone droneData;
        switch(msg.msgid){
            case MAVLINK_MSG_ID_ATTITUDE : //droneData.updateAttitude(msg);
            std::cout << "Attitude updated" << std::endl;
            break;
            case MAVLINK_MSG_ID_HEARTBEAT : //droneData.updateHeartbeat(msg);
            std::cout << "Heartbeat updated" << std::endl;
            break;
            case MAVLINK_MSG_ID_VFR_HUD : //droneData.updateHeadupDisplay(msg);
            std::cout << "HUD updated" << std::endl;
            break;
            default: //do nothing
            break;
        }
    }
}