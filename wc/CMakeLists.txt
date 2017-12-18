set(SOURCES wc.cpp)

lint(FILES ${SOURCES})
format(FILES ${SOURCES})

add_executable(wc ${SOURCES})
target_link_libraries(wc PUBLIC CLI11)
target_link_libraries(wc PUBLIC sum)
target_link_libraries(wc PUBLIC stringdata)
