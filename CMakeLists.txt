cmake_minimum_required(VERSION 3.16)

project(
    D2Q9LBMChannelFlow
    VERSION 1.0
    DESCRIPTION "2D D2Q9 Lattice Boltzmann Method Solver for Laminar Channel Flow"
    LANGUAGES CXX
)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Collect all source files
file(GLOB SRC_FILES
    src/*.cpp
)

# Executable
add_executable(
    d2q9_lbm
    ${SRC_FILES}
)

# Include directories
target_include_directories(
    d2q9_lbm
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Output executable to project root
set_target_properties(
    d2q9_lbm
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)