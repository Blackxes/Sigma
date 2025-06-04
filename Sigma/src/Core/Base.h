/**
 * @File This file is part of the Sigma game engine
 */

#pragma once

#ifdef SG_PLATFORM_WINDOWS
  #ifdef SG_BUILD_DLL
    #define SIGMA_API __declspec(dllexport)
  #else
    #define SIGMA_API __declspec(dllimport)
  #endif
#else
    #error Unsupported Platform. Currently only Windows is supported.
#endif

namespace Sigma
{
    /*
    // Aliases
    template<class T> using Ref = std::unique_ptr<T>;
    template <typename T, typename... Args>
    std::shared_ptr<T> MakeUnique(Args&&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T> using Shared = std::shared_ptr<T>;
    template <typename T, typename... Args>
    std::shared_ptr<T> MakeShared(Args&&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
    */
}