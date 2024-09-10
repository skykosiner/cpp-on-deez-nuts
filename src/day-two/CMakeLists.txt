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
    src/split/split_me_daddy.cpp
)

# Optionally add include directories if you have header files in different folders
# For example: include_directories(include)

# Link any libraries if needed
# For example: target_link_libraries(${APP_NAME} PRIVATE some_library)

# Optionally add compiler flags
# For example: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
