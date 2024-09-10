# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(cpp_on_deez_nuts VERSION 1.0)

# Specify C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the output binary name
set(APP_NAME cpp_on_deez_nuts)

# Add the executable and the source files
add_executable(${APP_NAME}
    src/main.cpp
    src/utils.cpp
)

