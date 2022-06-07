cmake_minimum_required(VERSION 3.20)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Mtmchkin.h
        Player.h
        Player.cpp
        Card.h
        Card.cpp
        test.cpp
        utilities.cpp
        utilities.h Card.h)
