#pragma once

#include "../Events/Event.h"

namespace Sigma
{
	class SIGMA_API Layer
	{
	public:
		virtual ~Layer() = 0;

		//virtual void OnAttach();
		//virtual void OnDetach();
		virtual void OnUpdate() = 0;
		//virtual void OnEvent(Event& evt);
	};

}