//
// Created by daniil on 23.10.17.
//

#include "evolution.hpp"
#include "mutation.hpp"


void create_initial_population (Genotype **population, size_t mu) {
    for (size_t i = 0; i < mu; i++) {
        auto *genotype = new Genotype;
        mu_change_start_position (*genotype);
        mu_change_exit_position (*genotype);

        for (int j = 0; j < 10; j++) {
            mu_add_room (*genotype);
            mu_add_monster (*genotype);
            mu_add_treasure (*genotype);
        }

        population [i] = genotype;
    }
}