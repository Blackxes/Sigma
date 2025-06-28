#pragma once

#include "Platform/PlatformDetection.h"

#include <chrono>

// API Export
#ifdef SIGMA_PLATFORM_WINDOWS
    #ifdef SIGMA_BUILD_DLL
        #define SIGMA_API __declspec(dllexport)
    #else
        #define SIGMA_API __declspec(dllimport)
    #endif
#else
    #error Unsupported Platform. Currently only Windows is supported.
#endif

// Debug-mode only code
#ifdef SIGMA_DEBUG
    #define DEBUG_CODE(code) code
#elif SIGMA_RELEASE
    #define DEBUG_CODE(code)
#endif

// Code executed on windows systems
#ifdef SIGMA_PLATFORM_WINDOWS
    #define ON_WINDOWS(code) code
#elif
    #define ON_WINDOWS(code)
#endif

// Type aliases
using uint = unsigned int;

using clock_type = std::chrono::high_resolution_clock;
