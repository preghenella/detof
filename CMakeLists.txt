project(detof)
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else()
    set(CMAKE_CXX_STANDARD 11)
endif()

find_package(Boost REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(detof src/detof.cxx)
target_link_libraries(detof ${Boost_PROGRAM_OPTIONS_LIBRARY})
install(TARGETS detof RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin)
