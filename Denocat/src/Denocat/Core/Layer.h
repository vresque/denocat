#pragma once

#include "Denocat/Core/Core.h"
#include "Denocat/Core/Timestep.h"
#include "Denocat/Events/Event.h"

namespace Denocat
{
	class VAPI Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}