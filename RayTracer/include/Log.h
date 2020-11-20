#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

class Log
{
public:
	static void init();
	static Ref<spdlog::logger>& getLogger() { return s_logger; }

private:
	static Ref<spdlog::logger> s_logger;
};

// Client log macros
#define LOG_TRACE(...)			Log::getLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)			Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)			Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)			Log::getLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)		Log::getLogger()->critical(__VA_ARGS__)