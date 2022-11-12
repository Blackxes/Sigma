#include "sgpch.h"
#include "Application.h"

extern Sigma::Application* Sigma::CreateApplication(Sigma::ApplicationCommandArgs);

namespace Sigma
{
	Application::Application(ApplicationCreationConfiguration creationConfig)
	{
		m_window = new sf::RenderWindow();
		m_window->create(
			{
				creationConfig.dimensions.x,
				creationConfig.dimensions.y
			},
			creationConfig.title
		);

		m_window->setPosition(creationConfig.initialPosition);
	}
}