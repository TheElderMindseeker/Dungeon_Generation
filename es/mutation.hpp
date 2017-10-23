//
// Created by Даниил on 23.10.2017.
//

#ifndef DUNGEON_GENERATION_MUTATION_HPP
#define DUNGEON_GENERATION_MUTATION_HPP


#include <random>
#include "Genotype.hpp"


extern std::default_random_engine engine;
void mutate (Genotype &genotype);

extern const int MU_ADD_ROOM;
void mu_add_room (Genotype &genotype);

extern const int MU_DELETE_ROOM;
void mu_delete_room (Genotype &genotype);

extern const int MU_CHANGE_ROOM;
void mu_change_room (Genotype &genotype);

extern const int MU_ADD_MONSTER;
void mu_add_monster (Genotype &genotype);

extern const int MU_ADD_TREASURE;
void mu_add_treasure (Genotype &genotype);

extern const int MU_DELETE_ENTITY;
void mu_delete_entity (Genotype &genotype);

extern const int MU_CHANGE_ENTITY_POSITION;
void mu_change_entity_position (Genotype &genotype);

extern const int MU_CHANGE_START_POSITION;
void mu_change_start_position (Genotype &genotype);

extern const int MU_CHANGE_EXIT_POSITION;
void mu_change_exit_position (Genotype &genotype);


#endif //DUNGEON_GENERATION_MUTATION_HPP
