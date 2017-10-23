//
// Created by Даниил on 23.10.2017.
//

#ifndef DUNGEON_GENERATION_MUTATION_HPP
#define DUNGEON_GENERATION_MUTATION_HPP


#include <random>
#include "Genotype.hpp"


extern std::default_random_engine engine;
void mutate (Genotype &genotype);

const int MU_ADD_ROOM = 0;
void mu_add_room (Genotype &genotype);

const int MU_DELETE_ROOM = 1;
void mu_delete_room (Genotype &genotype);

const int MU_CHANGE_ROOM = 2;
void mu_change_room (Genotype &genotype);

const int MU_ADD_CORRIDOR = 3;
void mu_add_corridor (Genotype &genotype);

const int MU_DELETE_CORRIDOR = 4;
void mu_delete_corridor (Genotype &genotype);

const int MU_CHANGE_CORRIDOR = 5;
void mu_change_corridor (Genotype &genotype);

const int MU_ADD_MONSTER = 6;
void mu_add_monster (Genotype &genotype);

const int MU_ADD_TREASURE = 7;
void mu_add_treasure (Genotype &genotype);

const int MU_DELETE_ENTITY = 8;
void mu_delete_entity (Genotype &genotype);

const int MU_CHANGE_ENTITY_POSITION = 9;
void mu_change_entity_position (Genotype &genotype);

const int MU_CHANGE_START_POSITION = 10;
void mu_change_start_position (Genotype &genotype);

const int MU_CHANGE_EXIT_POSITION = 11;
void mu_change_exit_position (Genotype &genotype);


#endif //DUNGEON_GENERATION_MUTATION_HPP
