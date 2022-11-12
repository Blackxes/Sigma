#pragma once

#include "../Events/Event.h"

namespace Sigma
{
	class Layer
	{
	public:
		virtual ~Layer();

		virtual void onAttach();
		virtual void onDetach();
		virtual void onUpdate();
		virtual void onEvent(Event& evt);
	};
}