#pragma once
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Event.h"
#include "ApplicationEvent.h"

#include "Timestep.h"
#include "ImGuiLayer.h"

int main(int argc, char** argv);


namespace Hazel
{
	class Application
	{
	private:
		//
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		//
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		static Application* s_Instance;
		float m_LastFrameTime = 0.0f;
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		friend int ::main(int argc, char** argv);
	public:
		Application();
		virtual ~Application();
		

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }

		

	};

	// define in client
	Application* CreateApplication();
}