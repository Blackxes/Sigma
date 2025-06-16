#pragma once

#include "ApplicationBase.h"

extern std::shared_ptr<Sigma::ApplicationBase> Sigma::CreateApplication(const Sigma::ApplicationCommandArgs& commandArgs);

int main(int argc, char** argv)
{
    auto app = Sigma::CreateApplication({ argc, argv });

    app->Init();
    app->Run();

    return 0;
}