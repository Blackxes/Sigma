
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
    }
    ~Sandbox() = default;

    bool OnInit() override
    {
        std::cout << "[Sandbox::OnInit]" << std::endl;

        return true;
    }

    bool OnEvent() override
    {
        std::cout << "[Sandbox::OnEvent]" << std::endl;

        return true;
    }

    bool OnShutdown() override
    {
        std::cout << "[Sandbox::OnShutdown]" << std::endl;

        return true;
    }
};

Sigma::ApplicationBase* Sigma::CreateApplication(const Sigma::ApplicationCommandArgs& args)
{
    Sigma::ApplicationCreationOptions creationOptions;
    creationOptions.title = "My very fancy Sandbox application";

    return new Sandbox(creationOptions);
}
