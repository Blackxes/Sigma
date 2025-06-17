#pragma once

#include "Sigma/Core/Base.h"
#include "Platform/Windows/WindowsRenderWindow.h"

#if defined(SIGMA_PLATFORM_WINDOWS)
    std::unique_ptr<Sigma::RenderWindowBase> CreateRenderWindow(const Sigma::RenderWindowCreationOptions& options)
    {
        return std::make_unique<Sigma::WindowsRenderWindow>();
    };
#else
    #error "Unsupported RenderWindow Platform"
#endif
