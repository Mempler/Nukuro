cmake_minimum_required(VERSION 3.14)
project(Nukoro)

set(CMAKE_CXX_STANDARD 11)
set(Nukoro_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(Nukoro STATIC
        src/game.cpp include/game.h
        src/window/window.cpp include/window/window.h
        src/graphics/Texture2D.cpp include/graphics/Texture2D.h)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)

add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

target_link_libraries(Nukoro ${OPENGL_gl_LIBRARY} glad glfw)

target_include_directories(Nukoro PUBLIC
        ${Nukoro_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        glfw glad)

add_subdirectory(examples)
