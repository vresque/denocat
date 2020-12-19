#pragma once

#include "Visionizer.h"

class Sandbox2D : public Visionizer::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Visionizer::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Visionizer::Event& e) override;
private:
	Visionizer::OrthographicCameraController m_CameraController;

	// Temp
	Visionizer::Ref<Visionizer::VertexArray> m_SquareVA;
	Visionizer::Ref<Visionizer::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};