cmake_minimum_required(VERSION 3.10)
project(SparkNG_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Create library from source files
add_library(sparkng_lib ${SOURCES})

# Test executable
file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(sparkng_test ${TEST_SOURCES})
target_link_libraries(sparkng_test sparkng_lib)

# Enable testing
enable_testing()
add_test(NAME sparkng_test COMMAND sparkng_test)
