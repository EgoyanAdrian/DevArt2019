cmake_minimum_required(VERSION 3.1)

project(da)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

set(HEADERS
	)

set(SOURCES
	src/main.cpp
	)

include_directories(include/lib/SFML)

add_executable(da ${SOURCES} ${HEADERS})
target_link_libraries(da sfml-graphics)
target_link_libraries(da sfml-system)
target_link_libraries(da sfml-window)
target_include_directories(da PRIVATE ${CMAKE_SOURCE_DIR}/include)