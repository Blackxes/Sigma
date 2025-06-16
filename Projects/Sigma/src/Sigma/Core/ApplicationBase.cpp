
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

        if (!this->Shutdown()) {
            // @todo Proper error logging and throwing
        }
    }

    bool ApplicationBase::Init()
    {
        std::cout << "[ApplicationBase::Init]" << std::endl;

        return this->OnInit();
    }

    void ApplicationBase::Run()
    {
        std::cout << "[ApplicationBase::Run]" << std::endl;

        if (!this->m_isRunning) {
            return;
        }

        for (const auto layer : this->m_layerCollection) {
            layer->OnUpdate(0.016f);
        }
    }

    bool ApplicationBase::Shutdown()
    {
        std::cout << "[ApplicationBase::Shutdown]" << std::endl;

        return this->OnShutdown();
    }

    void ApplicationBase::pushLayer(std::shared_ptr<LayerBase> layer)
    {
        this->m_layerCollection.pushLayer(layer);
    }
}