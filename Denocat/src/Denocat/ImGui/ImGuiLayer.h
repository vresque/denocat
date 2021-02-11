#pragma once

#include "Denocat/Core/Layer.h"

#include "Denocat/Events/ApplicationEvent.h"
#include "Denocat/Events/KeyEvent.h"
#include "Denocat/Events/MouseEvent.h"

namespace Denocat
{
	class VAPI ImGuiLayer : public Layer
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