#pragma once

#include "Denocat.h"

class Sandbox2D : public Denocat::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Denocat::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Denocat::Event& e) override;
private:
	Denocat::OrthographicCameraController m_CameraController;

	// Temp
	Denocat::Ref<Denocat::VertexArray> m_SquareVA;
	Denocat::Ref<Denocat::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};