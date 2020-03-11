#pragma once
#include "spdlog/spdlog.h"
namespace UNL::UAV{

class Log{
private:
	static std::shared_ptr<spdlog::logger> _LOGGER;
public:
	static void init();
	inline static std::shared_ptr<spdlog::logger>& getLogger(){ return _LOGGER;}
};
};