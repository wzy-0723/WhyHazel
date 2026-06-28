#include "hzpch.h"
#include "Hazel.h"

#include "OpenGLShader.h"


#include "OrthographicCameraController.h"
#include "EntryPoint.h"
#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox :public Hazel::Application
{
private:

public:
	Sandbox()
	{
		// 多层下，重设颜色会覆盖上一层
		PushLayer(new Sandbox2D());
		//PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}


};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}