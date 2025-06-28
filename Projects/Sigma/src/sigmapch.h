#pragma once

#include "Sigma/Core/Base.h"

#include <memory>
#include <string>

#include <type_traits>
#include <concepts>
#include <optional>
#include <chrono>
#include <thread>

#include <vector>
#include <unordered_map>

#ifdef SIGMA_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#ifdef SIGMA_DEBUG
	#include <iostream>
#endif
