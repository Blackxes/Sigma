
#include "WindowsRenderWindow.h"

namespace Sigma
{
    WindowsRenderWindow::WindowsRenderWindow()
    {
        if (!this->InitOpenGL()) {
            // @todo proper error handling
        }
    }

    bool WindowsRenderWindow::InitOpenGL()
    {
        // @todo proper error handling
        if (this->m_initialized) {
            return true;
        }

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        DEBUG_CODE(
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        );


        this->m_lastErrorCode = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        this->m_initialized = true;

        return this->m_initialized;
    }

    void* WindowsRenderWindow::CreateRenderWindow(const RenderWindowCreationOptions& options)
    {
        if (this->m_initialized) {
            return this->GetTypeExplicitRenderWindowHandle();
        }

        if (this->m_lastErrorCode) {
            // @todo proper error handling
            return nullptr;
        }

        this->m_windowHandle = glfwCreateWindow(
            options.dimensions.x,
            options.dimensions.y,
            options.title,
            options.fullScreen ? glfwGetPrimaryMonitor() : nullptr,
            nullptr
        );

        if (this->m_windowHandle == nullptr) {
            // @todo proper error handling
            glfwTerminate();
            return nullptr;
        }

        glfwMakeContextCurrent(this->m_windowHandle);

        return (void*) this->m_windowHandle;
    }

    void* WindowsRenderWindow::GetTypeExplicitRenderWindowHandle()
    {
        return (void*) this->m_windowHandle;
    }
}