
# version 3.8 or newer
cmake_minimum_required (VERSION 3.8)


# コンパイルオプションのチェック用マクロ
macro(FROG_PLANET_CHECK_COMPILE_OPTIONS)

if(NOT CompileOptionChecked)

    # コンパイルオプションの設定
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

    # カバレッジ計測ビルドオプション
    if(DEFINED ENV{FROG_PLANET_BUILD_CONFIG})
        if($ENV{FROG_PLANET_BUILD_CONFIG} STREQUAL "COVERAGE")
            message("Build with coverage")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
        endif()
    endif()

    set(CompileOptionChecked TRUE)

endif()

endmacro()

