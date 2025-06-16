
#include "ApplicationBase.h"

namespace Sigma
{
    ApplicationBase::ApplicationBase(const ApplicationCreationOptions& creationOptions)
    {
        std::cout << "[ApplicationBase::Constructor(ApplicationCreationOptions)]" << std::endl;
        this->creationOptions = creationOptions;
    }

    ApplicationBase::~ApplicationBase()
    {
        std::cout << "[ApplicationBase::Destructor]" << std::endl;
    }

    bool ApplicationBase::Init()
    {
        std::cout << "[ApplicationBase::Init]" << std::endl;

        this->m_initialized = true;
        this->m_isRunning = true;

        return true;
    }

    void ApplicationBase::Run()
    {
        std::cout << "[ApplicationBase::Run]" << std::endl;

        if (!this->m_initialized) {
            std::cout << "[ApplicationBase::Run] Skipped - Not initialized" << std::endl;
            return;
        }

        if (!this->m_isRunning) {
            std::cout << "[ApplicationBase::Run] Skipped - Running false" << std::endl;
            return;
        }

        for (const auto layer : this->m_layerCollection) {
            layer->OnUpdate(0.016f);
        }
    }

    void ApplicationBase::pushLayer(std::shared_ptr<LayerBase> layer)
    {
        this->m_layerCollection.pushLayer(layer);
    }
}