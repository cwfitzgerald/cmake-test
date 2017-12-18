find_package(PkgConfig REQUIRED)

pkg_check_modules(icu_io REQUIRED icu-io>=57 IMPORTED_TARGET)
pkg_check_modules(icu_uc REQUIRED icu-uc>=57 IMPORTED_TARGET)

set(SOURCES stringdata.cpp)
set(HEADERS include/stringdata.hpp)

lint(FILES ${SOURCES})
format(FILES ${SOURCES} ${HEADERS})

add_library(stringdata SHARED ${SOURCES})
target_include_directories(stringdata PUBLIC include)
target_link_libraries(stringdata PRIVATE PkgConfig::icu_uc PkgConfig::icu_io)
