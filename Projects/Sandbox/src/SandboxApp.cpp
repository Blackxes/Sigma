
#include <Sigma.h>
#include <Core/EntryPoint.h>

#include <iostream>

class Sandbox : public Sigma::ApplicationBase
{
public:
    Sandbox(const Sigma::ApplicationCreationOptions& options)
        : Sigma::ApplicationBase(options)
    {
    }

    ~Sandbox() = default;

    bool Init() override
    {
        std::cout << "[Sandbox::Init]" << std::endl;

        return true;
    }

    bool Run() override
    {
        std::cout << "[Sandbox::Run]" << std::endl;

        return true;
    }

    bool Shutdown() override
    {
        std::cout << "[Sandbox::Shutdown]" << std::endl;

        return true;
    }

};

Sigma::ApplicationBase* Sigma::CreateApplication(const Sigma::ApplicationCommandArgs& args)
{
    Sigma::ApplicationCreationOptions creationOptions;
    creationOptions.title = "My very fancy Sandbox application";

    return new Sandbox(creationOptions);
}
