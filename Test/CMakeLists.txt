

cmake_minimum_required (VERSION 3.8)

project(FrogPlanetTest C CXX)

set(AMPHAROS_ROOT ${CMAKE_SOURCE_DIR})
set(AMPHAROS_TEST_ROOT ${AMPHAROS_ROOT}/Test/FrogPlanet)

# include_directories
include_directories(
    ${AMPHAROS_ROOT}/Include
    ${AMPHAROS_ROOT}/External/googletest/googletest/include
)

# add_test_function
function(Add_FrogPlanet_Test name files)
    set(files ${files} ${AMPHAROS_TEST_ROOT}/RunAllTests.cpp)
    add_executable("${name}Test"  ${files})
    target_link_libraries("${name}Test" ${name} gtest)
    add_test(
        "${name}Test"
        "${name}Test"
    )
endfunction()


Add_FrogPlanet_Test(FrogPlanetLib ${AMPHAROS_TEST_ROOT}/FrogPlanetTest.cpp)
