#pragma once


#include "Visionizer/Renderer/GraphicsContext.h"



namespace Visionizer
{

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		// Inherted from GraphicsContext
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}