cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ASSIGNMENT1)

message("--Build CSC3002 Assignment1")

set(ASSIGNMENT1_DIR ${CMAKE_CURRENT_LIST_DIR})
include_directories(${ASSIGNMENT1_DIR}/src)
include_directories(${ASSIGNMENT1_DIR}/include)

file(GLOB ASSIGNMENT1_SOURCE ${ASSIGNMENT1_DIR}/src/*.cpp)
file(GLOB ASSIGNMENT1_HEADER ${ASSIGNMENT1_DIR}/include/*.h)
add_library(ASSIGNMENT1_LIB SHARED ${ASSIGNMENT1_SOURCE} ${ASSIGNMENT1_HEADER})

add_executable(ASSIGNMENT1_MAIN src/main.cpp ${ASSIGNMENT1_SOURCE} ${ASSIGNMENT1_HEADER})
target_link_libraries(ASSIGNMENT1_MAIN ASSIGNMENT1_LIB)
