/**
 * @File This file is part of the Sigma game engine
 */

#include "sgpch.h"
//#include "Core/Base.h"
//#include "Platform/Windows/WindowsWindow.h"
//#include "WindowsApplication.h"

//extern Sigma::Shared<Sigma::Application> Sigma::CreateApplication(const Sigma::ApplicationCommandArgs& commandArgs);

namespace Sigma
{
    /*
    bool WindowsApplication::Init()
    {
        if (this->m_initialized) {
            return true;
        }

        RenderWindowCreationOptions options = {
            this->m_creationConfiguration.title,
            this->m_creationConfiguration.dimensions.x,
            this->m_creationConfiguration.dimensions.y,
            this->m_creationConfiguration.fullScreen,
            false
        };

        this->m_window = MakeShared<WindowsWindow>(options);

        return false;
    }

    bool WindowsApplication::Run()
    {
        if (this->m_window->Create()) {
            throw "Couldn't create window";
        }

        GLFWwindow* windowHandle = this->m_window->GetWindowHandle<GLFWwindow>();

        while (!glfwWindowShouldClose(windowHandle)) {
            glfwPollEvents();

            if (glfwGetKey(windowHandle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(windowHandle, true);
            }

            glClearColor(1.0f, 0.5f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(windowHandle);
        }

        return true;
    }
    bool WindowsApplication::Shutdown()
    {
        return false;
    }
    */
}