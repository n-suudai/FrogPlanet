#pragma once

namespace FrogPlanet
{

struct IMalloc;
struct GenericPlatformMemory
{
  static IMalloc* BaseAllocator();
};

} // namespace FrogPlanet