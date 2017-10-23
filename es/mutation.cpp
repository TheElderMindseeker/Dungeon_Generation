//
// Created by Даниил on 23.10.2017.
//

#include "mutation.hpp"
#include "level_builder.hpp"


std::default_random_engine engine;
void mutate (Genotype &genotype) {
    static std::uniform_int_distribution<int> distribution (0, 8);

    int choice = distribution (engine);
    switch (choice) {
        case MU_ADD_ROOM:
            mu_add_room (genotype);
            break;

        case MU_DELETE_ROOM:
            mu_delete_room (genotype);
            break;

        case MU_CHANGE_ROOM:
            mu_change_room (genotype);
            break;

        case MU_ADD_MONSTER:
            mu_add_monster (genotype);
            break;

        case MU_ADD_TREASURE:
            mu_add_treasure (genotype);
            break;

        case MU_DELETE_ENTITY:
            mu_delete_entity (genotype);
            break;

        case MU_CHANGE_ENTITY_POSITION:
            mu_change_entity_position (genotype);
            break;

        case MU_CHANGE_START_POSITION:
            mu_change_start_position (genotype);
            break;

        case MU_CHANGE_EXIT_POSITION:
            mu_change_exit_position (genotype);
            break;

        default:
            // Do no mutation
            break;
    }
}

void mu_add_room (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 4);
    static std::uniform_int_distribution<int> size_distribution (3, 20);

    int x = position_distribution (engine);
    int y = position_distribution (engine);
    int w = size_distribution (engine);
    int h = size_distribution (engine);

    if (x + w >= LEVEL_SIZE)
        w = LEVEL_SIZE - (x + 1);
    if (y + h >= LEVEL_SIZE)
        h = LEVEL_SIZE - (y + 1);

    Room room { x, y, w, h };
    genotype.rooms.push_back (room);
}

void mu_delete_room (Genotype &genotype) {
    if (genotype.rooms.empty ())
        return;

    std::uniform_int_distribution<int> index_distribution (0, genotype.rooms.size () - 1);
    size_t index = (size_t) index_distribution (engine);

    auto iter = genotype.rooms.begin ();
    iter += index;
    genotype.rooms.erase (iter);
}

void mu_change_room (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 4);
    static std::uniform_int_distribution<int> size_distribution (3, 20);

    if (genotype.rooms.empty ())
        return;

    std::uniform_int_distribution<int> index_distribution (0, genotype.rooms.size () - 1);
    size_t index = (size_t) index_distribution (engine);

    int x = position_distribution (engine);
    int y = position_distribution (engine);
    int w = size_distribution (engine);
    int h = size_distribution (engine);

    if (x + w >= LEVEL_SIZE)
        w = LEVEL_SIZE - (x + 1);
    if (y + h >= LEVEL_SIZE)
        h = LEVEL_SIZE - (y + 1);

    Room room { x, y, w, h };

    genotype.rooms [index] = room;
}

void mu_add_monster (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Entity monster = { E_MONSTER, x, y };

    genotype.entities.push_back (monster);
}

void mu_add_treasure (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Entity treasure = { E_TREASURE, x, y };

    genotype.entities.push_back (treasure);
}

void mu_delete_entity (Genotype &genotype) {
    if (genotype.entities.empty ())
        return;

    std::uniform_int_distribution<int> index_distribution (0, genotype.entities.size () - 1);
    size_t index = (size_t) index_distribution (engine);

    auto iter = genotype.entities.begin ();
    iter += index;
    genotype.entities.erase (iter);
}

void mu_change_entity_position (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    if (genotype.entities.empty ())
        return;

    std::uniform_int_distribution<int> index_distribution (0, genotype.entities.size () - 1);
    size_t index = (size_t) index_distribution (engine);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Entity entity = { genotype.entities.at (index).e, x, y };

    genotype.entities [index] = entity;
}

void mu_change_start_position (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Point start = { x, y };

    genotype.start = start;
}

void mu_change_exit_position (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Point exit = { x, y };

    genotype.exit = exit;
}