//
// Created by daniil on 23.10.17.
//

#ifndef DUNGEON_GENERATION_EVOLUTION_HPP
#define DUNGEON_GENERATION_EVOLUTION_HPP


#include "Genotype.hpp"


void create_initial_population (Genotype **population, size_t mu);

void copy_parent_population (Genotype *population [], size_t pop_size, size_t mu);

void mutate_population (Genotype *population [], size_t pop_size, size_t mutate_factor);

void choose_fittest (Genotype *population [], size_t pop_size, size_t lambda);


#endif //DUNGEON_GENERATION_EVOLUTION_HPP
