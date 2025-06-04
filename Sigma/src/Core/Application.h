/**
 * @File This file is part of the Sigma game engine
 */

#pragma once

//#include "Core/Base.h"
//#include "Core/RenderWindow.h"
//#include "Container/Vector2D.h"

namespace Sigma
{
    /*
    class RenderWindow;
    class Application;

    struct SIGMA_API ApplicationCommandArgs
    {
        int argumentsCount = 0;
        char** arguments = nullptr;
    };

    struct SIGMA_API ApplicationCreationConfiguration
    {
        const char* title = "My first Sigma application";
        Vector2di dimensions = { 1200, 720 };
        bool fullScreen = false;
        const char* applicationDirectory = "";
    };

    // Defined in client application
    std::shared_ptr<Application> SIGMA_API CreateApplication(const ApplicationCommandArgs& commandArgs);

    class SIGMA_API Application
    {
    public:
        Application() = default;
        Application(const ApplicationCreationConfiguration& creationConfiguration);
        virtual ~Application();

        virtual bool Init() = 0;
        virtual bool Run() = 0;
        virtual bool Shutdown() = 0;

        /// <summary>
        /// Returns the application instance. CreateApplicationFromGlobal needs to be called prior
        /// The reason is to have a separation between creation and getting the application instance
        /// </summary>
        /// <returns>\ref Sigma::Application</returns>
        static std::shared_ptr<Application> Get()
        {
            if (m_instance == nullptr) {
                throw "Call Application::CreateApplication before using this function.";
            }

            return m_instance;
        }

        static std::shared_ptr<Application> CreateApplicationFromGlobal(const ApplicationCommandArgs& commandArgs)
        {
            m_instance = CreateApplication(commandArgs);

            return m_instance;
        }

    protected:
        bool m_initialized = false;
        static inline std::shared_ptr<Application> m_instance;
        ApplicationCreationConfiguration m_creationConfiguration;
        std::shared_ptr<RenderWindow> m_window = nullptr;
    };
    */
}