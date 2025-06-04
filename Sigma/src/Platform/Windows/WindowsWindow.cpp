/**
 * @File This file is part of the Sigma game engine
 */

//#include "sgpch.h"
//#include "WindowsWindow.h"

namespace Sigma
{
    /*
    bool WindowsWindow::Init()
    {
        // @todo proper error handling
        if (!this->InitializeOpenGL()) {
            return false;
        }

        return true;
    }

    bool WindowsWindow::Shutdown()
    {
        this->CloseWindow();

        return false;
    }

    bool WindowsWindow::InitializeOpenGL()
    {
        if (this->m_initialized) {
            return true;
        }

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        #ifdef _DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        #endif

        this->m_initialized = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        return this->m_initialized;
    }

    bool WindowsWindow::Create()
    {
        if (!this->m_initialized) {
            return false;
        }

        this->m_windowHandle = glfwCreateWindow(
            this->m_creationOptions.width,
            this->m_creationOptions.height,
            this->m_creationOptions.title,
            this->m_creationOptions.fullscreen ? glfwGetPrimaryMonitor() : nullptr,
            nullptr
        );

        if (this->m_windowHandle == nullptr) {
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(this->m_windowHandle);

        return true;
    }

    bool WindowsWindow::CloseWindow()
    {
        if (!m_isOpen) {
            return true;
        }

        glfwSetWindowShouldClose(this->m_windowHandle, true);
        glfwTerminate();

        return true;
    }

    bool WindowsWindow::CreateConsole()
    {
        throw "Not implemented";
    }
    */
}