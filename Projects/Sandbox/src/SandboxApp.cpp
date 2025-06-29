
#include <Sigma.h>
#include <Sigma/Core/EntryPoint.h>

#include <iostream>
#include <memory>
#include <string>

#include "ExampleLayer.h"

class Sandbox : public Sigma::ApplicationBase
{
public:
	Sandbox(const Sigma::ApplicationCreationOptions &options)
		: Sigma::ApplicationBase(options)
	{
		std::cout << "[Sandbox::Constructor]" << std::endl;

		this->PushLayer(std::make_shared<ExampleLayer>());
	}
	~Sandbox()
	{
		std::cout << "[Sandbox::Destructor]" << std::endl;
	}

	bool OnInit() override
	{
		std::cout << "[Sandbox::Init]" << std::endl;

		return true;
	}

	bool OnEvent() override
	{
		std::cout << "[Sandbox::OnEvent]" << std::endl;

		return true;
	}
};

std::shared_ptr<Sigma::ApplicationBase> Sigma::CreateApplication(const Sigma::ApplicationCommandArgs &args)
{
	Sigma::ApplicationCreationOptions creationOptions;
	creationOptions.title = "My very fancy Sandbox application";
	creationOptions.dimensions = {600, 300};
	creationOptions.fullScreen = false;
	creationOptions.targetUps = 120;

	return std::make_shared<Sandbox>(creationOptions);
}
