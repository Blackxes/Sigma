#pragma once

// Windows
#if !defined(SIGMA_PLATFORM_WINDOWS) && defined(_WIN32)
    #define SIGMA_PLATFORM_WINDOWS
#endif

#if defined(SIGMA_PLATFORM_WINDOWS) && defined(_WIN64)
    #define SIGMA_PLATFORM_WINDOWS_64
#else
    #error "Windows x84 systems are not supported"
#endif
