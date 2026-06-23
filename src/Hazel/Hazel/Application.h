#pragma once
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Event.h"
#include "ApplicationEvent.h"
namespace Hazel
{
	class HAZEL_API Application
	{
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	public:
		Application();
		virtual ~Application();
		

		void OnEvent(Event& e);
		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

		

	};

	// define in client
	Application* CreateApplication();
}