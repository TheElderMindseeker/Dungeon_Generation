#include <fstream>
#include <ctime>

#include "es/Genotype.hpp"
#include "es/mutation.hpp"
#include "es/display_dungeon.hpp"
#include "es/evolution.hpp"


int main (int argc, char **argv) {
    engine.seed (std::time (NULL));

    std::ofstream output ("result.txt");

    int dungeon [LEVEL_SIZE][LEVEL_SIZE];

    Genotype *population [10];
    const int mu = 10, lambda = 20;

    create_initial_population (population, mu);

    for (size_t i = 0; i < mu; i++) {
        Metainfo meta;
        generate_dungeon (static_cast<Genotype &&> (*population [i]), dungeon, meta);
        output_dungeon_image_ascii (output, dungeon);
        output << "\n\n------------------------------------------------------------\n\n\n";
    }

    output.close ();

    return 0;
}