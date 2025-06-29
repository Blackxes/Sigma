#pragma once

#include "Sigma/Core/Base.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <concepts>
#include <optional>
#include <functional>

#include <chrono>
#include <thread>

#include <print>
#include <format>

#ifdef SIGMA_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#ifdef SIGMA_DEBUG
	#include <iostream>
#endif
