//
// Created by daniil on 23.10.17.
//

#ifndef DUNGEON_GENERATION_LEVEL_EVALUATOR_HPP
#define DUNGEON_GENERATION_LEVEL_EVALUATOR_HPP


#include "level_builder.hpp"


// TODO: Add Doxygen documentation

void level_evaluator (int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo);

void reachable_area (int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo,
                     int start_x, int start_y);

float fitness (Metainfo &&metainfo);


#endif //DUNGEON_GENERATION_LEVEL_EVALUATOR_HPP
