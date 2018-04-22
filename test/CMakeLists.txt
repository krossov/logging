cmake_minimum_required(VERSION 3.2)

project(test_runner)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES src/main.cpp src/logging/logging_test.cpp)

set(GOOGLE_TEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/test/lib/googletest/include)

add_subdirectory(lib/googletest)

include_directories(${LOGGING_INCLUDE_DIR})
include_directories(${GOOGLE_TEST_INCLUDE_DIR})

add_executable(test_runner ${SOURCE_FILES})
target_link_libraries(test_runner logging gtest)

add_test(NAME test_runner COMMAND test_runner)
