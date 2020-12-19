#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_SquareVA = Visionizer::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	Visionizer::Ref<Visionizer::VertexBuffer> squareVB;
	squareVB.reset(Visionizer::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ Visionizer::ShaderDataType::Float3, "a_Position" }
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Visionizer::Ref<Visionizer::IndexBuffer> squareIB;
	squareIB.reset(Visionizer::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = Visionizer::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Visionizer::Timestep ts)
{
	float FPS = 1.0f / ts;
	VS_TRACE(FPS);
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Visionizer::RenderCommand::SetClearColor({ 0.1f, 0.2f, 0.1f, 1 });
	Visionizer::RenderCommand::Clear();

	Visionizer::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Visionizer::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Visionizer::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Visionizer::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	Visionizer::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Visionizer::Event& e)
{
	m_CameraController.OnEvent(e);
}