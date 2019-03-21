cmake_minimum_required(VERSION 3.14)
project(hello_window)

set(CMAKE_CXX_STANDARD 11)

add_executable(hello_window src/main.cpp)
target_include_directories(hello_window PRIVATE ${Nukoro_INCLUDE_DIR})
