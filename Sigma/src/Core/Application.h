#pragma once

#include "Sigma.h"
//#include "Layer.h"

int main(int argc, char** argv);

template class SIGMA_API sf::Vector2<int>;
template class SIGMA_API sf::Vector2<unsigned int>;

namespace Sigma
{

	struct SIGMA_API ApplicationCommandArgs
	{
		int argumentsCount = 0;
		char** arguments = nullptr;
	};

	struct SIGMA_API ApplicationCreationConfiguration
	{
		const char* title = "My first Sigma application";
		sf::Vector2u dimensions = { 1200, 720 };
		sf::Vector2i initialPosition = { 0, 0 };
	};

	class SIGMA_API Application
	{
	public:
		Application() = default;
		Application(const ApplicationCreationConfiguration& creationConfiguration);
		virtual ~Application();

		static Application& get()
		{
			return *m_instance;
		}

		//void pushLayer(Layer* layer);

	private:
		friend int ::main(int argc, char** argv);

		static Application* m_instance;
		sf::RenderWindow* m_window;

		ApplicationCreationConfiguration creationCommands;

		// Main application live
		bool init();
		bool run();
		bool shutdown();
	};

	// Defined in client application
	Application* CreateApplication(ApplicationCommandArgs commandArgs);

}