#include <iostream>
#include <ctime>

#include "es/Genotype.hpp"
#include "es/mutation.hpp"
#include "es/display_dungeon.hpp"


int main (int argc, char **argv) {
    engine.seed (std::time (NULL));

    Genotype genotype;
    mu_change_start_position (genotype);
    mu_change_exit_position (genotype);

    for (int i = 0; i < 10; i++) {
        mu_add_room (genotype);
        mu_add_monster (genotype);
        mu_add_treasure (genotype);
    }

    int dungeon [LEVEL_SIZE][LEVEL_SIZE];
    Metainfo meta;
    generate_dungeon (static_cast<Genotype &&> (genotype), dungeon, meta);

    output_dungeon_image_ascii (std::cout, dungeon);

    return 0;
}