cmake_minimum_required(VERSION 3.2)
project(logging C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES logging.h logging.cpp)

add_library(logging SHARED STATIC ${SOURCE_FILES})

install(TARGETS logging DESTINATION lib)
install(FILES logging.h DESTINATION include/logging)
