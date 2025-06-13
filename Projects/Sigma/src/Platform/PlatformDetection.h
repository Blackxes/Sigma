#pragma once

// Windows
#ifdef _WIN32
    #define SIGMA_PLATFORM_WINDOWS
    #define SIGMA_PLATFORM_WINDOWS_32
#elif _WIN64
    #define SIGMA_PLATFORM_WINDOWS
    #define SIGMA_PLATFORM_WINDOWS_64
#endif
