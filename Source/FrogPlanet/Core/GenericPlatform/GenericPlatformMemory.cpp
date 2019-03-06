#include "FrogPlanet/Core/GenericPlatform/GenericPlatformMemory.h"
#include "FrogPlanet/Core/HAL/IMalloc.h"

namespace FrogPlanet
{

struct GenericMalloc : public IMalloc
{
};

IMalloc* GenericPlatformMemory::BaseAllocator()
{
  static GenericMalloc malloc;
  return &malloc;
}

} // namespace FrogPlanet