#pragma once
#pragma warning(disable: 4251)

#include "Base.h"

namespace Sigma
{
	class SIGMA_API Clock
	{
	public:
		Clock(bool startClock = false)
		{
			if (startClock)
			{
				Start();
			}
		}

		void Start()
		{
			m_lastTime = clock_type::now();
		}

		Clock Update()
		{
			auto now = clock_type::now();
			m_lastDelta = std::chrono::duration_cast<std::chrono::nanoseconds>(
				now - m_lastTime.value_or(now)
			);
			m_lastTime = now;

			return *this;
		}

		float InSeconds() const { return (float) m_lastDelta.count() / 1'000'000'000; }
		float InMilliseconds() const { return (float) m_lastDelta.count() / 1'000'000; }
		float InMicroseconds() const { return (float) m_lastDelta.count() / 1'000; }
		float InNanoSeconds() const { return (float) m_lastDelta.count(); }

	private:
		std::chrono::nanoseconds m_lastDelta = {};
		std::optional<clock_type::time_point> m_lastTime = {};
	};
}