cmake_minimum_required(VERSION 3.17)
project(black_jack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g")
set(NCURSES_DIR "${CMAKE_SOURCE_DIR}/ncurses-6.2/myinstall")

find_library(NCURSES_LIB NAMES ncurses PATHS ${NCURSES_DIR}/lib)

include_directories(${NCURSES_DIR}/include)

add_executable(black_jack black_jack.cpp stack.cc)
target_link_libraries(black_jack ${NCURSES_LIB})


