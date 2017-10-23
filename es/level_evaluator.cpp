//
// Created by daniil on 23.10.17.
//

#include "level_evaluator.hpp"


void level_evaluator (int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo) {
    int start_x, start_y;

    int total_area = 0;
    for (int y = 0; y < LEVEL_SIZE; y++) {
        for (int x = 0; x < LEVEL_SIZE; x++) {
            if (dungeon [y][x] != VOID && dungeon [y][x] != WALL) {
                ++total_area;
                if (dungeon [y][x] == START) {
                    start_x = x;
                    start_y = y;
                }
            }
        }
    }
    metainfo.overall_area = total_area;

    if (! metainfo.start_exist)
        return;

    reachable_area (dungeon, metainfo, start_x, start_y);
}


void reachable_area (int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo,
                     int start_x, int start_y) {
    return;
}