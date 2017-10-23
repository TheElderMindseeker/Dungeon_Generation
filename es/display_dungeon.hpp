//
// Created by Даниил on 23.10.2017.
//

#ifndef DUNGEON_GENERATION_DISPLAY_DUNGEON_HPP
#define DUNGEON_GENERATION_DISPLAY_DUNGEON_HPP


#include <ostream>
#include "level_builder.hpp"


void output_dungeon_image_ascii (std::ostream &output, int dungeon [LEVEL_SIZE][LEVEL_SIZE]);


#endif //DUNGEON_GENERATION_DISPLAY_DUNGEON_HPP
