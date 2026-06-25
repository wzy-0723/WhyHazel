#include <imgui.h>
#include "Hazel.h"

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{

	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(Hazel::Event& event) override
	{

	}

};

class Sandbox :public Hazel::Application
{
private:

public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		//PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox()
	{

	}


};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}