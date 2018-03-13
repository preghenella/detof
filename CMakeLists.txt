project(detof)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else()
    set(CMAKE_CXX_STANDARD 11)
endif()

add_executable(detof src/detof.cxx)
target_link_libraries(detof)
install(TARGETS detof RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)
