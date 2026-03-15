cmake_minimum_required(VERSION 3.16)

project(OpenGLTemplate)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/glfw)

include_directories(
    external/glad/include
)

add_executable(OpenGLTemplate
    src/main.cpp
    src/glad.c
)

target_link_libraries(OpenGLTemplate glfw)