#pragma once

#include "Base.h"

namespace Sigma
{
    struct SIGMA_API ApplicationCommandArgs
    {
        int argumentsCount = 0;
        char** arguments = nullptr;
    };

    struct SIGMA_API ApplicationCreationOptions
    {
        const char* title = "My very first Sigma application.. wuhuu!";
    };

    class SIGMA_API ApplicationBase
    {
    public:
        ApplicationBase();
        ApplicationBase(const ApplicationCreationOptions& options);
        ApplicationBase(const ApplicationBase& rhs) = delete;
        virtual ~ApplicationBase();

        virtual bool Init() = 0;
        virtual bool Run() = 0;
        virtual bool Stop();
        virtual bool Shutdown() = 0;

    protected:
        bool m_isRunning = false;
        bool m_initialized = false;
        static inline ApplicationBase* m_instance = nullptr;
        ApplicationCreationOptions creationOptions = {};
    };

    extern ApplicationBase* CreateApplication(const ApplicationCommandArgs& commandArgs);
}
