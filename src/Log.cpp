#include "UAV/Log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace UNL::UAV{
std::shared_ptr<spdlog::logger> Log::_LOGGER;
std::shared_ptr<spdlog::logger> Log::_WRITER;
std::shared_ptr<spdlog::logger> Log::_READER;
void Log::init(){
	spdlog::set_pattern("%^[%T] %n: %v%$");
	_LOGGER = spdlog::stdout_color_mt("LOGGER");
	_LOGGER->set_level(spdlog::level::trace);

	_READER = spdlog::stdout_color_mt("Read");
	_READER->set_level(spdlog::level::trace);

	_WRITER = spdlog::stdout_color_mt("Write");
	_WRITER->set_level(spdlog::level::trace);

	_LOGGER->info("Started Logger!");
}
}