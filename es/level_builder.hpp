//
// Created by Даниил on 22.10.2017.
//

#ifndef DUNGEON_GENERATION_LEVEL_BUILDER_HPP
#define DUNGEON_GENERATION_LEVEL_BUILDER_HPP


#include "Genotype.hpp"
#include "Metainfo.hpp"


const int LEVEL_SIZE = 50;

const int VOID = 0;
const int FREE = 1;
const int WALL = 2;
const int MONSTER = 3;
const int TREASURE = 4;
const int START = 5;
const int EXIT = 6;


void generate_dungeon (const Genotype &genotype, int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo);


#endif //DUNGEON_GENERATION_LEVEL_BUILDER_HPP
