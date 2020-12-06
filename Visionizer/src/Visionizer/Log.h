#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Visionizer {

	class VISION_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define VS_CORE_TRACE(...)    ::Visionizer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VS_CORE_INFO(...)     ::Visionizer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VS_CORE_WARN(...)     ::Visionizer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VS_CORE_ERROR(...)    ::Visionizer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VS_CORE_CRITICAL(...) ::Visionizer::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define VS_TRACE(...)         ::Visionizer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VS_INFO(...)          ::Visionizer::Log::GetClientLogger()->info(__VA_ARGS__)
#define VS_WARN(...)          ::Visionizer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VS_ERROR(...)         ::Visionizer::Log::GetClientLogger()->error(__VA_ARGS__)
#define VS_CRITICAL(...)      ::Visionizer::Log::GetClientLogger()->critical(__VA_ARGS__)
