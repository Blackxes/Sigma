#pragma once

#include "Sigma/Container/Vector2.h"

namespace Sigma
{
    struct ApplicationCreationOptions;

    struct SIGMA_API RenderWindowCreationOptions
    {
        const char* title = "My very first Sigma application..wuhuu!";
        Vector2di dimensions = { 1280, 720 };
        bool fullScreen = false;
    };

    class RenderWindowBase
    {
    public:
        RenderWindowBase() { this->m_windowCount++; }
        virtual ~RenderWindowBase() { this->m_windowCount--; }

        virtual void* CreateRenderWindow(const RenderWindowCreationOptions& options) = 0;

        template<class T>
        T* GetWindowHandle() { return this->GetTypeExplicitRenderWindowHandle(); }
        int GetWindowCount() const { return this->m_windowCount; }

    protected:
        virtual void* GetTypeExplicitRenderWindowHandle() = 0;

    private:
        static inline int m_windowCount = 0;
    };
}

