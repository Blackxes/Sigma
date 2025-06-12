#pragma once

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