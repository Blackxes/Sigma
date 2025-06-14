
#include "ApplicationBase.h"

namespace Sigma
{
    ApplicationBase::ApplicationBase()
    {
        std::cout << "[ApplicationBase::ApplicationBase]" << std::endl;

        this->m_initialized = this->Init();
    }

    ApplicationBase::ApplicationBase(const ApplicationCreationOptions& creationOptions)
    {
        std::cout << "[ApplicationBase::Constructor(ApplicationCreationOptions)]" << std::endl;

        this->creationOptions = creationOptions;
        this->m_initialized = this->Init();
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

        return true;
    }

    bool ApplicationBase::Run()
    {
        std::cout << "[ApplicationBase::Run]" << std::endl;

        if (!this->m_isRunning) {
            return true;
        }

        return false;
    }

    bool ApplicationBase::Stop()
    {
        std::cout << "[ApplicationBase::Stop]" << std::endl;

        this->m_isRunning = false;

        return false;
    }

    bool ApplicationBase::Shutdown()
    {
        std::cout << "[ApplicationBase::Shutdown]" << std::endl;

        this->Stop();

        this->m_initialized = false;

        return true;
    }
}