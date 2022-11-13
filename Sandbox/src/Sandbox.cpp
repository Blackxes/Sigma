
#include <Sigma.h>
#include <Core\EntryPoint.h>

//PrintMessage("My Wonderful Penis is wonderful!");
//RenderWindow();

class Sandbox : public Sigma::Application
{
public:
	Sandbox(const Sigma::ApplicationCreationConfiguration& creationConfiguration)
	{
		std::cout << "Sandbox Application: " << creationConfiguration.title << std::endl;
	}

	~Sandbox()
	{
	}
};

Sigma::Application* Sigma::CreateApplication(Sigma::ApplicationCommandArgs commandArgs)
{
	Sigma::ApplicationCreationConfiguration config;
	config.dimensions = { 1200, 720 };
	config.initialPosition = { 0, 0 };
	config.title = "My super Sandbox";

	return new Sandbox(config);
}