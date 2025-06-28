
#include "sigmapch.h"
#include "ApplicationBase.h"
#include "Platform/RenderWindowCreation.h"

namespace Sigma
{
	ApplicationBase::ApplicationBase(const ApplicationCreationOptions &creationOptions)
	{
		std::cout << "[ApplicationBase::Constructor(ApplicationCreationOptions)]" << std::endl;
		m_creationOptions = creationOptions;
	}

	ApplicationBase::~ApplicationBase()
	{
		std::cout << "[ApplicationBase::Destructor]" << std::endl;
	}

	void ApplicationBase::Init()
	{
		m_windowInstance = ::CreateRenderWindow(m_creationOptions);

		OnInit();
	}

	void ApplicationBase::Run()
	{
		std::cout << "[ApplicationBase::Run]" << std::endl;

		if (!m_isRunning || m_creationOptions.targetUps == 0)
		{
			std::cout << "[ApplicationBase::Run] Skipped - Running false" << std::endl;
			return;
		}

		float currentTimer = 0;

		while (m_isRunning)
		{
			float delta = m_clock.Update().InSeconds();
			currentTimer += delta;

			if (currentTimer < 1.0f / m_creationOptions.targetUps)
			{
				continue;
			}

			for (const auto& layer : m_layerCollection)
			{
				layer->OnUpdate(currentTimer);
			}

			currentTimer -= 1.0f / m_creationOptions.targetUps;

			// Sleep thread to relief cpu
			float remainingTime = currentTimer - 1 / m_creationOptions.targetUps;

			if (remainingTime > 0.0f)
			{
				std::this_thread::sleep_for(
					std::chrono::microseconds((int) (remainingTime * 1'000'000))
				);
			}
		}
	}

	void ApplicationBase::PushLayer(std::shared_ptr<LayerBase> layer)
	{
		m_layerCollection.PushLayer(layer);
	}
}