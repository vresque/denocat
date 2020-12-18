#pragma once

#include "Visionizer/Layer.h"

#include "Visionizer/Events/ApplicationEvent.h"
#include "Visionizer/Events/KeyEvent.h"
#include "Visionizer/Events/MouseEvent.h"

namespace Visionizer {

	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}