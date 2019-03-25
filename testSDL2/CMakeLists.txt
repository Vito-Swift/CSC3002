project(testSDL2)

message("--Build SDL2 Test")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(SDL2Test main.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARY})
