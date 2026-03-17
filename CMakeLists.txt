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

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.c")

# Executable
add_executable(OpenGLTemplate ${SRC_FILES})


# Include paths
target_include_directories(OpenGLTemplate PRIVATE
    external/glad/include
    external/stb
)

# Link libraries
target_link_libraries(OpenGLTemplate
    glfw
)