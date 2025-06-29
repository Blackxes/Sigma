#pragma once

#include "../Base.h"
#include "EventBase.h"
#include <unordered_map>
#include <queue>


namespace Sigma
{
	class EventBus
	{
	public:
		template<class T> void AddListener(T type, std::function<T&> listener);
		template<class T> void RemoveListener(std::function<T&> listener);

		template <class T>
		bool Dispatch(std::shared_ptr<T> event);

		void HandleQueuedEvents();

	private:
		std::queue<std::shared_ptr<EventBase>> m_queue;
		std::unordered_map<std::type_index, std::list<std::function<bool(std::shared_ptr<EventBase>&)>>> m_listeners;
	};
}
