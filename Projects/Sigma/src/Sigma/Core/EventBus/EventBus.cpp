
#include "sigmapch.h"
#include "EventBus.h"

namespace Sigma
{
	template<class T>
	void EventBus::AddListener(T type, std::function<T&> listener)
	{
		static_assert(std::is_base_of<EventBase, T>::value, "Event type T must be of type EventBase");
	}

	template<class T>
	void EventBus::RemoveListener(std::function<T&> listener)
	{
		static_assert(std::is_base_of<EventBase, T>::value, "Event type T must be of type EventBase");
	}

	template<class T>
	bool EventBus::Dispatch(std::shared_ptr<T> event)
	{
		static_assert(std::is_base_of<EventBase, T>::value, "Event type T must be of type EventBase");

		//std::list<std::function<bool(std::shared_ptr<EventBase>&)>>
	}

	void EventBus::HandleQueuedEvents()
	{
		while(!m_queue.empty())
		{
			auto& evt = m_queue.front();

			if (evt == nullptr)
			{
				m_queue.pop();
				continue;
			}

			auto& callbacks = m_listeners[typeid(evt)];

			for (auto&& callback : callbacks)
			{
				callback(evt);
			}

			m_queue.pop();
		}
	}
}