#pragma once

#include "./EventType.h"

namespace Sigma
{
	enum class EventType
	{
		None = 0,
		KeyButtonPressed, KeyButtonReleased,
		MouseButtonLeft, MouseButtonRight,
	};

	// Event base class
	class Event
	{
	public:
		virtual inline EventType getEventType() const = 0;

	protected:
		bool m_handled = false;
	};

	// Handles the dispatching of events
	using EventCallbackFunction = std::function<void(Event&)>;
	class EventHandler
	{
	public:
		void dispatch();
		int listen(EventType type, EventCallbackFunction callback);
		void unlisten(int listenerId);
	};
}