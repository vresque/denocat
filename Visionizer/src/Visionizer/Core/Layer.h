#pragma once

#include "Visionizer/Core/Core.h"
#include "Visionizer/Core/Timestep.h"
#include "Visionizer/Events/Event.h"

namespace Visionizer
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