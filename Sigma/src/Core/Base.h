#pragma once

#ifdef SG_PLATFORM_WINDOWS
	#ifdef SG_BUILD_DLL
		#define SIGMA_API __declspec(dllexport)
	#else
		#define SIGMA_API __declspec(dllimport)
	#endif
#else
	#error Sigma doesn't support other platforms but Windows
#endif