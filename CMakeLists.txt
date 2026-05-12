cmake_minimum_required(VERSION 3.20)

# ==========================
# phaosfit project template
# ==========================
# - MY_PROJECT_NAME       : Name of project
# - EXECUTABLE_NAME       : Name of the final executable
# - src/                  : Root folder containing .c and .h files
# ==========================

set(MY_PROJECT_NAME "phaosfit")
set(EXECUTABLE_NAME "phaosfit")

# Name the project and specify C as the language
project(${MY_PROJECT_NAME} C)

# Use C17 (similar to -std=c17 from a Makefile)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)  # gives -std=c17 instead of -std=gnu17

# Collect all .c files under src/ recursively
# (adjust "src" if your sources are in another directory)
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

# Create the executable target
add_executable(${EXECUTABLE_NAME}
    ${PROJECT_SOURCES}
)

# Add the root src/ folder as an include directory
# (so headers like src/foo/bar.h are found)
target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Compiler flags similar to:
#   -std=c17 (handled above)
#   -Wall -Werror -g
target_compile_options(${EXECUTABLE_NAME} PRIVATE
    -Wall
    -Werror
    -g
)

message(STATUS "Building ${EXECUTABLE_NAME} with: C standard = C17, flags = -Wall -Werror -g")

# ==========================
# Usage (from the terminal)
# ==========================
# cmake -S . -B build
# cmake --build build
# ./build/phaosfit