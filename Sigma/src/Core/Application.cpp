#include "sgpch.h"
#include "Application.h"

extern Sigma::Application* Sigma::CreateApplication(Sigma::ApplicationCommandArgs commandArgs);

namespace Sigma
{
	Application* Application::m_instance = nullptr;

	Application::Application(const ApplicationCreationConfiguration& creationConfiguration)
	{
		if (m_instance != nullptr)
		{
			_ASSERT("An instance of the application is already created");
			__debugbreak();
		}

		m_instance = this;

		m_window = new sf::RenderWindow();
		m_window->create(
			{
				creationConfiguration.dimensions.x,
				creationConfiguration.dimensions.y
			},
			creationConfiguration.title
		);
		
		m_window->setPosition(creationConfiguration.initialPosition);

		std::cout << "ApplicationCreation: " << creationConfiguration.title << std::endl;
		std::cout << "Sigma::Application" << std::endl;

		init();
	}

	Application::~Application()
	{
		shutdown();
	}

	bool Application::init()
	{
		return true;
	}

	bool Application::run()
	{
		while (m_window->isOpen())
		{
			sf::Event evt;

			while (m_window->pollEvent(evt))
			{
				
			}
		}

		return true;
	}

	bool Application::shutdown()
	{
		return true;
	}
}