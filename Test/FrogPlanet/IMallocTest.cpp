#include "gtest/gtest.h"
#include "FrogPlanet/Core/HAL/PlatformMemory.h"


namespace {

class IMallocTest : public ::testing::Test
{
};

TEST(IMallocTest, Create)
{
    FrogPlanet::IMalloc* pMalloc = FrogPlanet::PlatformMemory::BaseAllocator();
    ASSERT_NE(nullptr, pMalloc);
}

}


