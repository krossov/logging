cmake_minimum_required(VERSION 3.2)

enable_testing()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(LOGGING_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)
