#include "vspch.h"
#include "Texture.h"
#include "Visionizer/Core.h"
#include <string>

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Visionizer
{
	Ref<Texture2D> Visionizer::Texture2D::Create(const std::string& path)
	{
		// [TODO] Make this work...
		VS_INFO("Loading image from {0}", path);
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    VS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLTexture2D>(path);
		}
		VS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
