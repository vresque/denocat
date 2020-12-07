#pragma once

#include <memory>;

#ifdef VS_PLATFORM_WINDOWS
#if VS_DYNAMIC_LINK
	#ifdef VS_BUILD_DLL
		#define VISION_API __declspec(dllexport)
	#else
		#define VISION_API __declspec(dllimport)
	#endif
#else
    #define VISION_API
#endif
#else
	#error Visionizer only supports Windows!
#endif

#ifdef VS_DEBUG
	#define VS_ENABLE_ASSERTS
#endif

#ifdef VS_ENABLE_ASSERTS
	#define VS_ASSERT(x, ...) { if(!(x)) { VS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VS_CORE_ASSERT(x, ...) { if(!(x)) { VS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VS_ASSERT(x, ...)
	#define VS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define VS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


namespace Visionizer
{
	template<typename T>
	using Scope = std::unique_ptr<T>;


	template<typename T>
	using Ref = std::shared_ptr<T>;

}