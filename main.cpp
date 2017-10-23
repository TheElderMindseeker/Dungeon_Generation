#include <fstream>
#include <ctime>

#include "es/Genotype.hpp"
#include "es/mutation.hpp"
#include "es/display_dungeon.hpp"
#include "es/evolution.hpp"
#include "es/level_evaluator.hpp"


int main (int argc, char **argv) {
    engine.seed ((unsigned) std::time (NULL));

    std::ofstream output ("result.txt");

    int dungeon [LEVEL_SIZE][LEVEL_SIZE];

    const int mu = 20, lambda = 40;
    std::vector<Genotype> population (mu + lambda);

    create_initial_population (population, mu);

    for (int i = 0; i < 32; i++) {
        copy_parent_population (population, mu + lambda, mu);
        mutate_population (population, mu + lambda, 10);
        choose_fittest (population, mu + lambda);
    }

    for (int i = 0; i < mu; i++) {
        Metainfo metainfo;
        generate_dungeon (population [i], dungeon, metainfo);
        level_evaluator (dungeon, metainfo);
        output_dungeon_image_ascii (output, dungeon);
        output << "\nScore: " << fitness (static_cast<Metainfo &&> (metainfo))
               << "\n--------------------------------------------------\n\n\n";
    }

    output.close ();

    return 0;
}