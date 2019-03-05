#include "gtest/gtest.h"
#include "FrogPlanet/FrogPlanet.h"

namespace {

class FrogPlanetTest : public ::testing::Test
{
};

TEST(FrogPlanetTest, HelloFrogPlanet)
{
    testing::internal::CaptureStdout();

    FrogPlanet::Hello();

    ASSERT_STREQ("Hello, FrogPlanet!\n",
                 testing::internal::GetCapturedStdout().c_str());
}

}