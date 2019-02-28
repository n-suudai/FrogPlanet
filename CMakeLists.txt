
cmake_minimum_required (VERSION 3.8)

project(FrogPlanet C CXX)


if(MSVC)
    message("MSVC")
    # remove unnecessary warnings about unchecked iterators
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    foreach (flag_var
             CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
             CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if (NOT BUILD_SHARED_LIBS AND NOT gtest_force_shared_crt)
        string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
      endif()
      string(REPLACE "/W3" "/W4 /WX" ${flag_var} "${${flag_var}}")
      message("${${flag_var}}")
    endforeach()
else()
    message("NOT MSVC")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
    if(COMPILER_SUPPORTS_CXX14)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
    elseif(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
    else()
      message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()
endif()

# target_sources で相対パスを絶対パスに変換して使用
# 参照 : https://cmake.org/cmake/help/v3.13/policy/CMP0076.html
if (POLICY CMP0076)
  cmake_policy(SET CMP0076 NEW)
endif (POLICY CMP0076)


set(AMPHAROS_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(AMPHAROS_SRC_ROOT ${AMPHAROS_ROOT}/Source/FrogPlanet)

# External
add_subdirectory(
    External
)


# include_directories
include_directories(
    ${AMPHAROS_ROOT}/Include
)


# FrogPlanetLib
set(
    FrogPlanetLibSources
    ${AMPHAROS_SRC_ROOT}/FrogPlanet.cpp
)

add_library(FrogPlanetLib ${FrogPlanetLibSources})

# FrogPlanetMain
set(
    FrogPlanetMainSources
    ${AMPHAROS_SRC_ROOT}/Main.cpp
)
add_executable(FrogPlanetMain ${FrogPlanetMainSources})
target_link_libraries(FrogPlanetMain FrogPlanetLib gtest gtest_main)



# CTest
add_subdirectory(Test)
