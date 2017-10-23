//
// Created by daniil on 23.10.17.
//

#include <stack>
#include <cmath>
#include "level_evaluator.hpp"


void level_evaluator (int dungeon [LEVEL_SIZE][LEVEL_SIZE], Metainfo &metainfo) {
    int start_x = 0, start_y = 0;

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
    static bool visited [LEVEL_SIZE][LEVEL_SIZE];
    int curr_x = start_x, curr_y = start_y;
    std::stack<std::pair<int, int>> path;

    for (int y = 0; y < LEVEL_SIZE; y++)
        for (int x = 0; x < LEVEL_SIZE; x++)
            visited [y][x] = false;

    int reachable = 1;
    path.push (std::make_pair (start_x, start_y));
    visited [start_y][start_x] = true;
    while (! path.empty ()) {
        if (curr_y > 0 && dungeon [curr_y - 1][curr_x] != VOID && dungeon [curr_y - 1][curr_x] != WALL && ! visited [curr_y - 1][curr_x]) {
            path.push (std::make_pair (curr_x, curr_y));
            --curr_y;
            visited [curr_y][curr_x] = true;
            ++reachable;

            if (dungeon [curr_y][curr_x] == EXIT)
                metainfo.exit_reachable = true;
        }
        else if (curr_x < LEVEL_SIZE - 1 && dungeon [curr_y][curr_x + 1] != VOID && dungeon [curr_y][curr_x + 1] != WALL && ! visited [curr_y][curr_x + 1]) {
            path.push (std::make_pair (curr_x, curr_y));
            ++curr_x;
            visited [curr_y][curr_x] = true;
            ++reachable;

            if (dungeon [curr_y][curr_x] == EXIT)
                metainfo.exit_reachable = true;
        }
        else if (curr_y < LEVEL_SIZE - 1 && dungeon [curr_y + 1][curr_x] != VOID && dungeon [curr_y + 1][curr_x] != WALL && ! visited [curr_y + 1][curr_x]) {
            path.push (std::make_pair (curr_x, curr_y));
            ++curr_y;
            visited [curr_y][curr_x] = true;
            ++reachable;

            if (dungeon [curr_y][curr_x] == EXIT)
                metainfo.exit_reachable = true;
        }
        else if (curr_x > 0 && dungeon [curr_y][curr_x - 1] != VOID && dungeon [curr_y][curr_x - 1] != WALL && ! visited [curr_y][curr_x - 1]) {
            path.push (std::make_pair (curr_x, curr_y));
            --curr_x;
            visited [curr_y][curr_x] = true;
            ++reachable;

            if (dungeon [curr_y][curr_x] == EXIT)
                metainfo.exit_reachable = true;
        }
        else {
            curr_x = path.top ().first;
            curr_y = path.top ().second;
            path.pop ();
        }
    }

    metainfo.reachable_area = reachable;
}


float fitness (Metainfo &&metainfo) {
    return 100.0f + 100.0f * ((float) metainfo.reachable_area / metainfo.overall_area)
           + (metainfo.start_exist ? 200.0f : 0.0f)
           + (metainfo.exit_exist ? 100.0f : 0.0f)
           + (metainfo.exit_reachable ? 50.0f : 0.0f)
           - 10.0f * (std::abs ((float) metainfo.treasures - metainfo.monsters));
}