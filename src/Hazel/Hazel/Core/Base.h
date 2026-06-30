#pragma once
#include <memory>
#ifdef _WIN32
	#ifdef _WIN64
		#define HZ_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__linux__)
	#define HZ_PLATFORM_LINUX
	#error "Linux is not supported!"
#elif defined(__APPLE__)
	#error "macOS is not supported!"
#else
	#error "Unknown target platform!"
#endif

#if defined(HZ_PLATFORM_WINDOWS)
	#define HZ_DEBUGBREAK() __debugbreak()
#elif defined(HZ_PLATFORM_LINUX)
	#include <signal.h>
	#define HZ_DEBUGBREAK() raise(SIGTRAP)
#else
	#error "Platform doesn't support debugbreak yet!"
#endif



#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); HZ_DEBUGBREAK(); } }
#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); HZ_DEBUGBREAK(); } }

#define BIT(x) (1 << x)		// 将1左移x位

//#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#define HZ_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
namespace Hazel 
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}


	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}