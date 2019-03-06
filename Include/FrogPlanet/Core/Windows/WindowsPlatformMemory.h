#pragma once

#include "FrogPlanet/Core/GenericPlatform/GenericPlatformMemory.h"

namespace FrogPlanet
{

struct WindowsPlatformMemory : public GenericPlatformMemory
{
};

typedef WindowsPlatformMemory PlatformMemory;

} // namespace FrogPlanet
