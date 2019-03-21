cmake_minimum_required(VERSION 3.14)
project(Nukoro)

set(CMAKE_CXX_STANDARD 11)
set(Nukoro_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

add_library(Nukoro STATIC
        src/game.cpp include/game.h
        src/window/window.cpp include/window/window.h
        )

target_link_libraries(Nukoro SDL2 ${GLEW_LIBRARIES} GL)
target_include_directories(Nukoro PUBLIC ${Nukoro_INCLUDE_DIR} ${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})

add_subdirectory(examples)
