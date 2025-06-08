#pragma once

#ifdef SIGMA_BUILD_DLL
#define SIGMA_API __declspec(dllexport)
#else
#define SIGMA_API __declspec(dllimport)
#endif