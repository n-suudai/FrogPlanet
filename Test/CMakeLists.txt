

# version 3.8 or newer
cmake_minimum_required (VERSION 3.8)


# 「FrogPlanetTest」
project(FrogPlanetTest C CXX)


# テストソースファイルのルートパス
set(FROG_PLANET_TEST_ROOT ${FROG_PLANET_ROOT}/Test/FrogPlanet)


# include_directories
include_directories(
    ${ExternalIncludeDirs}
    ${FROG_PLANET_ROOT}/Include
    ${FROG_PLANET_ROOT}/External/googletest/googletest/include
)


# テスト追加用関数
function(frog_planet_test name files)
    set(files ${files} ${FROG_PLANET_TEST_ROOT}/RunAllTests.cpp)
    add_executable("${name}Test"  ${files})
    target_link_libraries("${name}Test" ${name} gtest)
    add_test(
        "${name}Test"
        "${name}Test"
    )
endfunction()


frog_planet_test(FrogPlanetLib ${FROG_PLANET_TEST_ROOT}/FrogPlanetTest.cpp)
