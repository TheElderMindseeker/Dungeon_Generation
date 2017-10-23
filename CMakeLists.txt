cmake_minimum_required (VERSION 3.8)
project (Dungeon_Generation)

set (CMAKE_CXX_STANDARD 11)

set (SOURCE_FILES
        main.cpp
        es/Genotype.hpp
        es/level_builder.cpp
        es/level_builder.hpp
        es/Metainfo.hpp
        es/level_evaluator.cpp
        es/level_evaluator.hpp
        )
add_executable (Dungeon_Generation ${SOURCE_FILES})