#pragma once
#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Event.h"
#include "ApplicationEvent.h"
#include "ImGuiLayer.h"
#include "Shader.h"
namespace Hazel
{
	class HAZEL_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		static Application* s_Instance;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		std::unique_ptr<Shader> m_Shader;
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();
		

		void OnEvent(Event& e);
		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

		

	};

	// define in client
	Application* CreateApplication();
}