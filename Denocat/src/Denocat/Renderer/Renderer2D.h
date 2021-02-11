#pragma once
#include "OrthographicCamera.h"
#include <glm/glm.hpp>

namespace Denocat
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();
		

		// Primitives
		static void DrawQuad(const glm::vec2& position, )

	};
}