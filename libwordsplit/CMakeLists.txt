find_package(PkgConfig REQUIRED)

pkg_check_modules(icu_io REQUIRED icu-io>=57 IMPORTED_TARGET)
pkg_check_modules(icu_uc REQUIRED icu-uc>=57 IMPORTED_TARGET)

set(SOURCES wordsplit.cpp)
set(HEADERS include/wordsplit.hpp)

lint(FILES ${SOURCES})
format(FILES ${SOURCES} ${HEADERS})

add_library(wordsplit SHARED ${SOURCES})
target_include_directories(wordsplit PUBLIC include)
target_link_libraries(wordsplit PRIVATE PkgConfig::icu_uc PkgConfig::icu_io)
