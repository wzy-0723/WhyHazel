#pragma once
#include "Layer.h"
#include <GLFW/glfw3.h>
#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"

namespace Hazel 
{
	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;


		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
		
	};

}