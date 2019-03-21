cmake_minimum_required(VERSION 3.14)
project(hello_texture)

set(CMAKE_CXX_STANDARD 11)

add_executable(hello_texture src/main.cpp)
target_include_directories(hello_texture PRIVATE ${Nukoro_INCLUDE_DIR})
