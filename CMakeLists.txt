cmake_minimum_required(VERSION 3.16)
project(OpenGLTemplate)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# GLM (header-only)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

# GLFW
add_subdirectory(external/glfw)

# Executable
add_executable(OpenGLTemplate
    src/main.cpp
    src/glad.c
    src/stb_image.cpp
)

# Include paths
target_include_directories(OpenGLTemplate PRIVATE
    external/glad/include
    external/stb
)

# Link libraries
target_link_libraries(OpenGLTemplate
    glfw
)