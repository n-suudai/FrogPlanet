
# version 3.8 or newer
cmake_minimum_required (VERSION 3.8)


# インクルードディレクトリを追加
include_directories(
    ${ExternalIncludeDirs}
)


# 「FrogPlanetLib」
add_library(FrogPlanetLib ${FROG_PLANET_SRC_ROOT}/FrogPlanet.cpp)
cotire(FrogPlanetLib)


# 「FrogPlanetMain」
add_executable(FrogPlanetMain ${FROG_PLANET_SRC_ROOT}/Main.cpp)
target_link_libraries(FrogPlanetMain FrogPlanetLib)
cotire(FrogPlanetMain)

