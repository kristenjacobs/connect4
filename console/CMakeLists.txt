cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/engine)

add_executable(console
    ConsoleDisplayer.cpp
    ConsolePlayer.cpp
    Main.cpp)

target_link_libraries(console 
    ${CMAKE_BINARY_DIR}/engine/libengine.a)

