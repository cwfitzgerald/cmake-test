cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

project(CMakeTest CXX)

set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED True)

include("cmake-utils/include/clang_format.cmake")
include("cmake-utils/include/linter.cmake")
include("cmake-utils/include/warnings.cmake")

add_subdirectory(third-party/libsimdpp)
include("third-party/libsimdpp/cmake/SimdppMultiarch.cmake")

add_warnings()

add_linted_subdirectory(libwordsplit)
add_linted_subdirectory(libsum)

configure_linter()
