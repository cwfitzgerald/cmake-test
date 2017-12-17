set(SOURCES sum.cpp)
set(HEADERS include/sum.hpp)

simdpp_get_compilable_archs(ARCHES)
simdpp_multiarch(ARCH_SOURCES ${SOURCES} ${ARCHES})

lint(FILES ${SOURCES})
format(FILES ${SOURCES} ${HEADERS})

add_library(sum SHARED ${ARCH_SOURCES})
target_include_directories(sum PUBLIC include)
target_include_directories(sum SYSTEM PRIVATE "../third-party/libsimdpp")
