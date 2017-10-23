//
// Created by daniil on 23.10.17.
//

#ifndef DUNGEON_GENERATION_EVOLUTION_HPP
#define DUNGEON_GENERATION_EVOLUTION_HPP


#include <cstddef>

#include "Genotype.hpp"
#include "level_builder.hpp"


struct GenotypeComparator {
    bool operator () (const Genotype &a, const Genotype &b);

    int dungeon_a [LEVEL_SIZE][LEVEL_SIZE];
    int dungeon_b [LEVEL_SIZE][LEVEL_SIZE];
};

void create_initial_population (std::vector<Genotype> &population, size_t mu);

void copy_parent_population (std::vector<Genotype> &population, size_t pop_size, size_t mu);

void mutate_population (std::vector<Genotype> &population, size_t pop_size, size_t mutate_factor);

void choose_fittest (std::vector<Genotype> &population, size_t pop_size);


#endif //DUNGEON_GENERATION_EVOLUTION_HPP
