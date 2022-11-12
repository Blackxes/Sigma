#pragma once

#include <functional>
#include <memory.h>
#include <vector>

#include "./EventHandler.h"
#include "./Event.h"

namespace Engine {

	using EventCallbackSignature = void(EventBase);

	class EventHandler {
		private:
			std::vector<EventCallbackSignature> listener;

		public:
			EventHandler();
			~EventHandler();

			int listen(EventType eventType, std::function<EventCallbackSignature> callback);
			bool unlisten(int listenerId);
			int replaceCallback(int listenerId, std::function<bool(EventBase)> callback);
	};
}