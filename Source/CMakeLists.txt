
# version 3.8 or newer
cmake_minimum_required (VERSION 3.8)


# インクルードディレクトリを追加
include_directories(
    ${ExternalIncludeDirs}
)

# 「FrogPlanetCore」
set(FROG_PLANET_CORE_SRC_ROOT ${FROG_PLANET_SRC_ROOT}/Core)
add_library(
    FrogPlanetCore
    ${FROG_PLANET_CORE_SRC_ROOT}/GenericPlatform/GenericPlatformMemory.cpp
)
cotire(FrogPlanetCore)


# 「FrogPlanetLib」
add_library(FrogPlanetLib 
    ${FROG_PLANET_SRC_ROOT}/FrogPlanet.cpp

)
cotire(FrogPlanetLib)


# 「FrogPlanetMain」
add_executable(FrogPlanetMain ${FROG_PLANET_SRC_ROOT}/Main.cpp)
# add_executable(FrogPlanetMain WIN32 ${FROG_PLANET_SRC_ROOT}/Main.cpp) # WinMainを使いたい場合、WIN32属性？を指定する必要がある
target_link_libraries(FrogPlanetMain FrogPlanetLib FrogPlanetCore)
cotire(FrogPlanetMain)

