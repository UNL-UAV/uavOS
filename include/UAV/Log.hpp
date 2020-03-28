#pragma once
#include "spdlog/spdlog.h"
namespace UNL::UAV{

class Log{
private:
	static std::shared_ptr<spdlog::logger> _LOGGER;
	static std::shared_ptr<spdlog::logger> _WRITER;
	static std::shared_ptr<spdlog::logger> _READER;
public:
	static void init();
	inline static std::shared_ptr<spdlog::logger>& getLogger(){ return _LOGGER;}
	inline static std::shared_ptr<spdlog::logger>& getWriter(){ return _WRITER;}
	inline static std::shared_ptr<spdlog::logger>& getReader(){ return _READER;}
};
};