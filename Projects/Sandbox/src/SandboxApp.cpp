
#include <Sigma.h>
#include <Sigma/Core/EntryPoint.h>

#include <iostream>
#include <memory>
#include <string>

#include "ExampleLayer.h"

class Sandbox : public Sigma::ApplicationBase
{
public:
    Sandbox(const Sigma::ApplicationCreationOptions& options)
        : Sigma::ApplicationBase(options)
    {
        std::cout << "[Sandbox::Constructor]" << std::endl;

        this->pushLayer(std::make_shared<ExampleLayer>());
    }
    ~Sandbox()
    {
        std::cout << "[Sandbox::Destructor]" << std::endl;
    }

    bool OnEvent() override
    {
        std::cout << "[Sandbox::OnEvent]" << std::endl;

        return true;
    }
};

std::shared_ptr<Sigma::ApplicationBase> Sigma::CreateApplication(const Sigma::ApplicationCommandArgs& args)
{
    Sigma::ApplicationCreationOptions creationOptions;
    creationOptions.title = "My very fancy Sandbox application";

    return std::make_unique<Sandbox>(creationOptions);
}
