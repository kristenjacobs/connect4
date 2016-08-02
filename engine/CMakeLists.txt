cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-unused-result" )

add_library(engine STATIC 
    Board.cpp
    CMakeLists.txt
    ComputerPlayer.cpp
    BoardEvaluator.cpp
    Counter.cpp
    Game.cpp
    Direction.cpp
    NullDisplayer.cpp)


