//
// Created by Даниил on 22.10.2017.
//

#include "level_builder.hpp"


void generate_dungeon (const Genotype &genotype, int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo) {
    for (int i = 0; i < LEVEL_SIZE; i++)
        for (int j = 0; j < LEVEL_SIZE; j++)
            dungeon [i][j] = VOID;

    for (auto iter = genotype.rooms.begin (); iter != genotype.rooms.end (); iter++) {
        for (int x = iter->x; x < iter->x + iter->w; x++) {
            if (dungeon [iter->y][x] != FREE)
                dungeon [iter->y][x] = WALL;
            if (dungeon [iter->y + iter->h - 1][x] != FREE)
                dungeon [iter->y + iter->h - 1][x] = WALL;
        }
        for (int y = iter->y; y < iter->y + iter->h; y++) {
            if (dungeon [y][iter->x] != FREE)
                dungeon [y][iter->x] = WALL;
            if (dungeon [y][iter->x + iter->w - 1] != FREE)
                dungeon [y][iter->x + iter->w - 1] = WALL;
        }
        for (int y = iter->y + 1; y < iter->y + iter->h - 1; y++) {
            for (int x = iter->x + 1; x < iter->x + iter->w - 1; x++) {
                dungeon [y][x] = FREE;
            }
        }
    }

    for (auto iter = genotype.corridors.begin (); iter != genotype.corridors.end (); iter++) {
        if (iter->orientation == ORI_VERTICAL) {
            for (int x = iter->axe - 1; x <= iter->axe + 1; x++) {
                if (dungeon[iter->start - 1][x] != FREE)
                    dungeon[iter->start - 1][x] = WALL;
                if (dungeon[iter->finish + 1][x] != FREE)
                    dungeon[iter->finish + 1][x] = WALL;
            }

            for (int y = iter->start; y <= iter->finish; y++) {
                if (dungeon [y][iter->axe - 1] != FREE)
                    dungeon [y][iter->axe - 1] = WALL;
                if (dungeon [y][iter->axe + 1] != FREE)
                    dungeon [y][iter->axe + 1] = WALL;

                if (dungeon [y][iter->axe] == WALL) {
                    dungeon [y][iter->axe] = DOOR;
                }
                else {
                    dungeon[y][iter->axe] = FREE;
                }
            }
        }
        else if (iter->orientation == ORI_HORIZONTAL) {
            for (int y = iter->axe - 1; y <= iter->axe + 1; y++) {
                if (dungeon [y][iter->start - 1] != FREE)
                    dungeon [y][iter->start - 1] = WALL;
                if (dungeon [y][iter->finish + 1] != FREE)
                    dungeon [y][iter->finish + 1] = WALL;
            }

            for (int x = iter->start; x <= iter->finish; x++) {
                if (dungeon [iter->axe - 1][x] != FREE)
                    dungeon [iter->axe - 1][x] = WALL;
                if (dungeon [iter->axe + 1][x] != FREE)
                    dungeon [iter->axe + 1][x] = WALL;

                if (dungeon [iter->axe][x] == WALL) {
                    dungeon [iter->axe][x] = DOOR;
                }
                else {
                    dungeon[iter->axe][x] = FREE;
                }
            }
        }
    }

    for (auto iter = genotype.entities.begin (); iter != genotype.entities.end (); iter++) {
        if (dungeon [iter->y][iter->x] == FREE) {
            if (iter->type == 0) {
                dungeon [iter->y][iter->x] = MONSTER;
                ++metainfo.monsters;
            }
            else {
                dungeon [iter->y][iter->x] = TREASURE;
                ++metainfo.treasures;
            }
        }
    }

    if (dungeon [genotype.start.y][genotype.start.x] == FREE) {
        dungeon [genotype.start.y][genotype.start.x] = START;
        metainfo.start_exist = true;
    }
    if (dungeon [genotype.exit.y][genotype.exit.x] == FREE) {
        dungeon [genotype.exit.y][genotype.exit.x] = EXIT;
        metainfo.exit_exist = true;
    }
}