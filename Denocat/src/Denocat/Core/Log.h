#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Denocat
{
	class VAPI Log
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
#define  VS_CORE_TRACE(...)    ::Denocat::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define  VS_CORE_INFO(...)     ::Denocat::Log::GetCoreLogger()->info(__VA_ARGS__)
#define  VS_CORE_WARN(...)     ::Denocat::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define  VS_CORE_ERROR(...)    ::Denocat::Log::GetCoreLogger()->error(__VA_ARGS__)
#define  VS_CORE_CRITICAL(...) ::Denocat::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define  VS_TRACE(...)         ::Denocat::Log::GetClientLogger()->trace(__VA_ARGS__)
#define  VS_INFO(...)          ::Denocat::Log::GetClientLogger()->info(__VA_ARGS__)
#define  VS_WARN(...)          ::Denocat::Log::GetClientLogger()->warn(__VA_ARGS__)
#define  VS_ERROR(...)         ::Denocat::Log::GetClientLogger()->error(__VA_ARGS__)
#define  VS_CRITICAL(...)      ::Denocat::Log::GetClientLogger()->critical(__VA_ARGS__)
