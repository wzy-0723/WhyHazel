#pragma once
#include "hzpch.h"
#include "Core.h"
namespace Hazel {

	// Events in Hazel are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryInput          = BIT(1),
		EventCategoryKeyboard       = BIT(2),
		EventCategoryMouse          = BIT(3),
		EventCategoryMouseButton    = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		bool Handled = false;


		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}
		template<typename T>
		using EventFn = std::function<bool(T&)>;

		//template<typename T>
		//bool Dispatch(EventFn<T> func)
		//{
		//	if (m_Event.GetEventType() == T::GetStaticType())
		//	{
		//		/*
		//			&m_Event：取基类 Event 对象的地址 Event*
		//			(T*)&m_Event：C 风格强制转型，把基类指针转为派生事件指针 T*（如WindowResizeEvent*）
		//			*(T*)&m_Event：解引用，得到派生类引用 T&
		//			func(...)：把派生事件引用传入回调函数执行
		//			返回的 bool 赋值给 m_Event.m_Handled：标记事件是否被处理
		//		*/
		//		m_Event.Handled = func(*(T*)&m_Event);
		//		return true;
		//	}
		//	return false;
		//}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

	//进行一个概念约束，模板类型必须为Event的派生类，最后特化formater，C++20特性
	template <typename T>
	concept EventDerived = std::is_base_of_v<Event, T>;	
	template <Hazel::EventDerived Event>
	struct fmt::formatter<Event> : fmt::formatter<std::string> 
	{
		template <typename FormatContext>
		auto format(const Event& e, FormatContext& ctx) const {
			return fmt::format_to(ctx.out(), "{}", e.ToString());
		}
	};
}

