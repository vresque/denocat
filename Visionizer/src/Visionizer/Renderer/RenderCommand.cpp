#include "vspch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Visionizer {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}