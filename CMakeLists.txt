cmake_minimum_required(VERSION 3.20)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Mtmchkin.h
        Players/Player.h
        Players/Player.cpp
        Cards/Card.cpp
        Cards/Card.h
        Cards/Barfight.h
        Cards/Barfight.cpp
        Cards/Fairy.cpp
        Cards/Fairy.h
        Cards/Pitfall.cpp
        Cards/Pitfall.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Vampire.cpp
        Cards/Vampire.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Goblin.cpp
        Cards/Goblin.h
        Cards/BattleCard.cpp
        Cards/BattleCard.h
        test.cpp
        utilities.cpp
        utilities.h
        Mtmchkin.cpp
        Players/Rogue.cpp
        Players/Rogue.h
        Players/Wizard.cpp
        Players/Wizard.h
        Players/Fighter.cpp
        Players/Fighter.h dependencies.h)
