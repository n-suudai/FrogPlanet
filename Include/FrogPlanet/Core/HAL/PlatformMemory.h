#pragma once

#include "FrogPlanet/Core/HAL/Platform.h"


#if FROG_PLANET_PLATFORM_WINDOWS
#include "FrogPlanet/Core/Windows/WindowsPlatformMemory.h"
#else
#error Unknown platform
#endif

