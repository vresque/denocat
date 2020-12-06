#include <Visionizer.h>

#include "imgui/imgui.h"

class ExampleLayer : public Visionizer::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Visionizer::Input::IsKeyPressed(VKEY_TAB))
			VS_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Visionizer::Event& event) override
	{
		if (event.GetEventType() == Visionizer::EventType::KeyPressed)
		{
			Visionizer::KeyPressedEvent& e = (Visionizer::KeyPressedEvent&)event;
			if (e.GetKeyCode() == VKEY_TAB)
				VS_TRACE("Tab key is pressed (event)!");
			VS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Visionizer::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Visionizer::Application* Visionizer::CreateApplication()
{
	return new Sandbox();
}