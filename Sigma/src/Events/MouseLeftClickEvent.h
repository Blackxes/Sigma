#pragma once

#include "../Event.h";

namespace Sigma {
	namespace Events {
		class MouseLeftClickEvent : public EventBase {
			public:
				MouseLeftClickEvent() {
					EventBase(EventType::MOUSE_LEFT_CLICK);
				};
				~MouseLeftClickEvent() = default;
		};
	}
}