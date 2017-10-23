//
// Created by Даниил on 22.10.2017.
//


#ifndef DUNGEON_GENERATION_GENOTYPE_HPP
#define DUNGEON_GENERATION_GENOTYPE_HPP


#include <vector>


struct Room {
    int x;
    int y;
    int w;
    int h;
};


struct Entity {
    int e;
    int x;
    int y;
};


struct Point {
    int x;
    int y;
};


struct Genotype {
    std::vector<Room> rooms;
    std::vector<Entity> entities;
    Point start;
    Point exit;
};


#endif //DUNGEON_GENERATION_GENOTYPE_HPP
