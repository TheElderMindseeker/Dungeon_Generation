//
// Created by Даниил on 22.10.2017.
//

#ifndef DUNGEON_GENERATION_LEVEL_BUILDER_HPP
#define DUNGEON_GENERATION_LEVEL_BUILDER_HPP


#include "Genotype.hpp"
#include "Metainfo.hpp"


const int LEVEL_SIZE = 50;

extern const int VOID;
extern const int FREE;
extern const int WALL;
extern const int MONSTER;
extern const int TREASURE;
extern const int START;
extern const int EXIT;


void generate_dungeon(Genotype &&genotype, int dungeon[LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo);


#endif //DUNGEON_GENERATION_LEVEL_BUILDER_HPP
