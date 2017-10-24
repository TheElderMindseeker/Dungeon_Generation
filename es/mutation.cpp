//
// Created by Даниил on 23.10.2017.
//

#include "mutation.hpp"
#include "level_builder.hpp"


std::default_random_engine engine;


void mutate (Genotype &genotype) {
    static std::uniform_int_distribution<int> distribution (0, 11);

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

        case MU_ADD_CORRIDOR:
            mu_add_corridor (genotype);
            break;

        case MU_DELETE_CORRIDOR:
            mu_delete_corridor (genotype);
            break;

        case MU_CHANGE_CORRIDOR:
            mu_change_corridor (genotype);
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
    static std::uniform_int_distribution<int> size_distribution (5, 15);

    int x = position_distribution (engine);
    int y = position_distribution (engine);
    int w = size_distribution (engine);
    int h = size_distribution (engine);

    if (x + w >= LEVEL_SIZE)
        w = LEVEL_SIZE - (x + 1);
    if (y + h >= LEVEL_SIZE)
        h = LEVEL_SIZE - (y + 1);

    Room room{x, y, w, h};
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
    static std::uniform_int_distribution<int> size_distribution (5, 10);

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

    Room room{x, y, w, h};

    genotype.rooms[index] = room;
}


void mu_add_corridor (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (1, 4);
    static std::uniform_int_distribution<int> length_distribution (5, 10);
    static std::uniform_int_distribution<int> type_distribution (ORI_VERTICAL, ORI_HORIZONTAL);

    if (genotype.rooms.empty ())
        return;

    std::uniform_int_distribution<int> room_distribution (0, (unsigned) genotype.rooms.size () - 1);
    int room_index = room_distribution (engine);
    Room room = genotype.rooms.at ((unsigned long) room_index);

    int s, f, a, ori;

    switch (position_distribution (engine)) {
        case 1:
            ori = ORI_VERTICAL;
            s = room.y;
            f = std::max (room.y - length_distribution (engine), 1);
            a = (2 * room.x + room.w) / 2;
            break;

        case 2:
            ori = ORI_HORIZONTAL;
            s = room.x + room.w;
            f = std::min (room.x + room.w + length_distribution (engine), LEVEL_SIZE - 2);
            a = (2 * room.y + room.h) / 2;
            break;

        case 3:
            ori = ORI_VERTICAL;
            s = room.y + room.h;
            f = std::min (room.y + room.h + length_distribution (engine), LEVEL_SIZE - 2);
            a = (2 * room.x + room.w) / 2;
            break;

        case 4:
            ori = ORI_HORIZONTAL;
            s = room.x;
            f = std::max (room.x - length_distribution (engine), 1);
            a = (2 * room.y + room.h) / 2;
            break;

        default:
            return;
    }

    Corridor corridor { s, f, a, ori };
    genotype.corridors.push_back (corridor);
}


void mu_delete_corridor (Genotype &genotype) {
    if (genotype.corridors.empty ())
        return;

    std::uniform_int_distribution<int> index_distribution (0, genotype.corridors.size () - 1);
    size_t index = (size_t) index_distribution (engine);

    auto iter = genotype.corridors.begin ();
    iter += index;
    genotype.corridors.erase (iter);
}


void mu_change_corridor (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (1, 4);
    static std::uniform_int_distribution<int> length_distribution (5, 10);
    static std::uniform_int_distribution<int> type_distribution (ORI_VERTICAL, ORI_HORIZONTAL);

    if (genotype.corridors.empty () || genotype.rooms.empty ())
        return;

    std::uniform_int_distribution<int> room_distribution (0, (unsigned) genotype.rooms.size () - 1);
    std::uniform_int_distribution<int> index_distribution (0, (unsigned) genotype.corridors.size () - 1);
    int room_index = room_distribution (engine);
    int index = index_distribution (engine);
    Room room = genotype.rooms.at ((unsigned long) room_index);

    int s, f, a, ori;

    switch (position_distribution (engine)) {
        case 1:
            ori = ORI_VERTICAL;
            s = room.y;
            f = std::max (room.y - length_distribution (engine), 1);
            a = (2 * room.x + room.w) / 2;
            break;

        case 2:
            ori = ORI_HORIZONTAL;
            s = room.x + room.w;
            f = std::min (room.x + room.w + length_distribution (engine), LEVEL_SIZE - 2);
            a = (2 * room.y + room.h) / 2;
            break;

        case 3:
            ori = ORI_VERTICAL;
            s = room.y + room.h;
            f = std::min (room.y + room.h + length_distribution (engine), LEVEL_SIZE - 2);
            a = (2 * room.x + room.w) / 2;
            break;

        case 4:
            ori = ORI_HORIZONTAL;
            s = room.x;
            f = std::max (room.x - length_distribution (engine), 1);
            a = (2 * room.y + room.h) / 2;
            break;

        default:
            return;
    }

    Corridor corridor { s, f, a, ori };
    genotype.corridors [index] = corridor;
}


void mu_add_monster (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Entity monster = {E_MONSTER, x, y};

    genotype.entities.push_back (monster);
}


void mu_add_treasure (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Entity treasure = {E_TREASURE, x, y};

    genotype.entities.push_back (treasure);
}


void mu_delete_entity (Genotype &genotype) {
    if (genotype.entities.empty ())
        return;

    std::uniform_int_distribution<int> index_distribution (0, (unsigned) genotype.entities.size () - 1);
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

    Entity entity = {genotype.entities.at (index).type, x, y};

    genotype.entities[index] = entity;
}


void mu_change_start_position (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Point start = {x, y};

    genotype.start = start;
}


void mu_change_exit_position (Genotype &genotype) {
    static std::uniform_int_distribution<int> position_distribution (0, LEVEL_SIZE - 1);

    int x = position_distribution (engine);
    int y = position_distribution (engine);

    Point exit = {x, y};

    genotype.exit = exit;
}