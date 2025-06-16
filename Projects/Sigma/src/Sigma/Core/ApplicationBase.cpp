
#include "ApplicationBase.h"
#include "Platform/RenderWindowCreation.h"

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

    void ApplicationBase::Init()
    {
        //this->m_windowInstance = ::CreateRenderWindow(creationOptions);

        this->OnInit();
    }

    void ApplicationBase::Run()
    {
        std::cout << "[ApplicationBase::Run]" << std::endl;

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