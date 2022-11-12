#pragma once

#include "Sigma.h"
#include "Layer.h"

int main(int argc, char** argv);

namespace Sigma
{

	struct ApplicationCommandArgs
	{
		int argumentsCount;
		char** arguments = nullptr;
	};

	struct ApplicationCreationConfiguration
	{
		const char* title = "My first Sigma application";
		sf::Vector2u dimensions = { 1200, 720 };
		sf::Vector2i initialPosition = { 0, 0 };
	};

	class Application
	{
	public:
		Application(ApplicationCreationConfiguration creationConfiguration);
		virtual ~Application() = 0;

		static Application& get() { return *m_instance; }

		void pushLayer(Layer* layer);

	private:
		friend int ::main(int argc, char** argv);
		static Application* m_instance;
		sf::RenderWindow* m_window;

		// Main application live
		virtual bool init() = 0;
		virtual bool run() = 0;
		virtual bool shutdown() = 0;


	};

	// Defined in client application
	Application* CreateApplication(ApplicationCommandArgs commandArgs);
}