cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(CMakeTest CXX)

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED True)

include("cmake-utils/include/clang_format.cmake")
include("cmake-utils/include/linter.cmake")
include("cmake-utils/include/make_target_includes_system.cmake")
include("cmake-utils/include/warnings.cmake")

add_subdirectory(third-party/libsimdpp)
include("third-party/libsimdpp/cmake/SimdppMultiarch.cmake")

add_subdirectory(third-party/CLI11)
make_target_includes_system(CLI11)

add_warnings()

add_linted_subdirectory(libstringdata)
add_linted_subdirectory(libsum)
add_linted_subdirectory(wc)

configure_linter()
