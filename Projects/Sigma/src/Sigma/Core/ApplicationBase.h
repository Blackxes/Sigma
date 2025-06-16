#pragma once

#include "Base.h"
#include "LayerBase.h"
#include "LayerCollection.h"

int main(int argc, char** argv);

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
        ApplicationBase(const ApplicationCreationOptions& options);
        virtual ~ApplicationBase();

        void pushLayer(std::shared_ptr<LayerBase> layer);
        static std::shared_ptr<ApplicationBase> Get() { return m_instance; }

        virtual bool OnEvent() = 0;

    private:
        friend int ::main(int argc, char** argv);
        bool Init();
        void Run();

    private:
        bool m_isRunning = false;
        bool m_initialized = false;
        static inline std::shared_ptr<ApplicationBase> m_instance = nullptr;
        ApplicationCreationOptions creationOptions = {};
        LayerCollection m_layerCollection;
    };

    extern std::shared_ptr<ApplicationBase> CreateApplication(const ApplicationCommandArgs& commandArgs);
}
