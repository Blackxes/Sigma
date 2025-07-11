#pragma once

#include "Base.h"
#include "RenderWindowBase.h"
#include "LayerBase.h"
#include "LayerCollection.h"
#include "Clock.h"

extern int main(int argc, char** argv);

namespace Sigma
{
    struct SIGMA_API ApplicationCommandArgs
    {
        int argumentsCount = 0;
        char** arguments = nullptr;
    };

    struct SIGMA_API ApplicationCreationOptions : public RenderWindowCreationOptions
    {
        uint targetUps = 1;
    };

    class SIGMA_API ApplicationBase
    {
    public:
        friend int ::main(int argc, char** argv);

        ApplicationBase(const ApplicationCreationOptions& options);
        virtual ~ApplicationBase();

        void PushLayer(std::shared_ptr<LayerBase> layer);
        static std::shared_ptr<ApplicationBase> Get() { return m_instance; }

        virtual bool OnInit() = 0;
        virtual bool OnEvent() = 0;

    private:
        void Init();
        void Run();

    private:
        bool m_isRunning = true;
        Clock m_clock;

        ApplicationCreationOptions m_creationOptions = {};
        static inline std::shared_ptr<ApplicationBase> m_instance = nullptr;
        static inline std::unique_ptr<RenderWindowBase> m_windowInstance = nullptr;

        LayerCollection m_layerCollection = {};
    };

    extern std::shared_ptr<ApplicationBase> CreateApplication(const ApplicationCommandArgs& commandArgs);
}
