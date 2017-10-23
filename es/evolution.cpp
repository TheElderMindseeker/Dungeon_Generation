//
// Created by daniil on 23.10.17.
//

#include <algorithm>

#include "evolution.hpp"
#include "mutation.hpp"
#include "level_evaluator.hpp"


/*int GenotypeComparator::dungeon_a [LEVEL_SIZE][LEVEL_SIZE];
int GenotypeComparator::dungeon_b [LEVEL_SIZE][LEVEL_SIZE];

Metainfo GenotypeComparator::meta_a;
Metainfo GenotypeComparator::meta_b;*/


bool GenotypeComparator::operator () (const Genotype &a, const Genotype &b) {
    Metainfo meta_a;
    Metainfo meta_b;

    generate_dungeon (a, dungeon_a, meta_a);
    generate_dungeon (b, dungeon_b, meta_b);

    level_evaluator (dungeon_a, meta_a);
    level_evaluator (dungeon_b, meta_b);

    return fitness (static_cast<Metainfo &&> (meta_a)) > fitness (static_cast<Metainfo &&> (meta_b));
}


void create_initial_population (std::vector<Genotype> &population, size_t mu) {
    for (size_t i = 0; i < mu; i++) {
        Genotype genotype;
        mu_change_start_position (genotype);
        mu_change_exit_position (genotype);

        for (int j = 0; j < 10; j++) {
            mu_add_room (genotype);
            mu_add_monster (genotype);
            mu_add_treasure (genotype);
        }

        population [i] = genotype;
    }
}


void copy_parent_population (std::vector<Genotype> &population, size_t pop_size, size_t mu) {
    for (size_t i = 0, j = mu; j < pop_size; i++, j++) {
        Genotype genotype;
        genotype.rooms = std::vector<Room> (population [i].rooms);
        genotype.entities = std::vector<Entity> (population [i].entities);
        genotype.start = population [i].start;
        genotype.exit = population [i].exit;

        population [j] = genotype;
    }
}


void mutate_population (std::vector<Genotype> &population, size_t pop_size, size_t mutate_factor) {
    for (size_t i = 0; i < pop_size; i++) {
        for (size_t j = 0; j < mutate_factor; j++) {
            mutate (population[i]);
        }
    }
}


void choose_fittest (std::vector<Genotype> &population, size_t pop_size) {
    GenotypeComparator comparator;

    for (size_t i = 1; i < pop_size; i++) {
        for (size_t j = i; j > 0 && comparator (population [j], population [j - 1]); j--) {
            Genotype temp = population [j];
            population [j] = population [j - 1];
            population [j - 1] = temp;
        }
    }
}
