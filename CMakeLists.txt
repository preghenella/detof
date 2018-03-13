project(detof)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 11)

add_executable(detof detof.cxx)
target_link_libraries(detof)
