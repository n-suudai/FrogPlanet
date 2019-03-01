
# version 3.8 or newer
cmake_minimum_required (VERSION 3.8)


# 「FrogPlanet」
project(FrogPlanet C CXX)


# 「FrogPlanet」 のプロジェクトルートパスを設定
set(FROG_PLANET_ROOT ${CMAKE_CURRENT_LIST_DIR})


# 「FrogPlanet」のソースファイルルートパス
set(FROG_PLANET_SRC_ROOT ${FROG_PLANET_ROOT}/Source/FrogPlanet)


# 「CompileOption.cmake」を追加
include(${FROG_PLANET_ROOT}/CMake/CompileOption.cmake)
FROG_PLANET_CHECK_COMPILE_OPTIONS()


# target_sources で相対パスを絶対パスに変換して使用
# 参照 : https://cmake.org/cmake/help/v3.13/policy/CMP0076.html
if (POLICY CMP0076)
  cmake_policy(SET CMP0076 NEW)
endif (POLICY CMP0076)


# 外部ライブラリのインクルードディレクトリ
set(
    ExternalIncludeDirs
    ${FROG_PLANET_ROOT}/Include
    ${FROG_PLANET_ROOT}/External/EASTL/Include
)

# プリコンパイル済みヘッダを使用するため「cotire」を追加
set(CMAKE_MODULE_PATH ${FROG_PLANET_ROOT}/External/cotire/CMake)
include(cotire)

# プリコンパイルの対象に設定
set(
    COTIRE_PREFIX_HEADER_INCLUDE_PATH
    ${COTIRE_PREFIX_HEADER_INCLUDE_PATH}
    ${ExternalIncludeDirs}
)


# 外部ライブラリ (include_directoriesより前にある必要がある？)
add_subdirectory(
    External
)


# 「FrogPlanet」
add_subdirectory(
    Source
)


# テスト
enable_testing()
add_subdirectory(Test)
