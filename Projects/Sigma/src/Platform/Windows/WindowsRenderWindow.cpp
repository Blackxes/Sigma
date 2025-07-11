
#include "sigmapch.h"
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
        if (m_initialized) {
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


        m_lastErrorCode = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        m_initialized = true;

        return m_initialized;
    }

    void* WindowsRenderWindow::CreateRenderWindow(const RenderWindowCreationOptions& options)
    {
        if (m_initialized) {
            return this->GetTypeExplicitRenderWindowHandle();
        }

        if (m_lastErrorCode) {
            // @todo proper error handling
            return nullptr;
        }

        m_windowHandle = glfwCreateWindow(
            options.dimensions.x,
            options.dimensions.y,
            options.title,
            options.fullScreen ? glfwGetPrimaryMonitor() : nullptr,
            nullptr
        );

        if (m_windowHandle == nullptr) {
            // @todo proper error handling
            glfwTerminate();
            return nullptr;
        }

        glfwMakeContextCurrent(m_windowHandle);

        return (void*) m_windowHandle;
    }

    void* WindowsRenderWindow::GetTypeExplicitRenderWindowHandle()
    {
        return (void*) m_windowHandle;
    }
}