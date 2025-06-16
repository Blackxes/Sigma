#pragma once
#pragma warning(disable: 4251)

#include "Sigma/Core/Base.h"
#include "Sigma/Core/RenderWindowBase.h"
#include "Sigma/Core/ApplicationBase.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sigma
{
    class SIGMA_API WindowsRenderWindow : public RenderWindowBase
    {
    public:
        WindowsRenderWindow();
        virtual ~WindowsRenderWindow() = default;

        bool InitOpenGL();
        void* CreateRenderWindow(const RenderWindowCreationOptions& options);

    private:
        int m_lastErrorCode = -1;
        bool m_initialized = false;
        GLFWwindow* m_windowHandle = nullptr;

        void* GetTypeExplicitRenderWindowHandle() override;
    };
}