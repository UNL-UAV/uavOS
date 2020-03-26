#pragma once
#include "common/mavlink.h"
namespace UNL::UAV{
class PacketBuilder{
	virtual mavlink_message_t& build() = 0;
};
class StaticPacketBuilder : public PacketBuilder{
	mavlink_message_t& build() = 0;
};
};