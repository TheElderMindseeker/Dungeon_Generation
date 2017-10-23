//
// Created by Даниил on 22.10.2017.
//


#ifndef DUNGEON_GENERATION_GENOTYPE_HPP
#define DUNGEON_GENERATION_GENOTYPE_HPP


#include <vector>


const int E_MONSTER = 0;
const int E_TREASURE = 1;


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
    Genotype () = default;

    Genotype (const Genotype &other) : rooms (other.rooms), entities (other.entities) {
        this->start = other.start;
        this->exit = other.exit;
    }

    const Genotype &operator = (const Genotype &other) {
        this->rooms = other.rooms;
        this->entities = other.entities;
        this->start = other.start;
        this->exit = other.exit;
    }

    std::vector<Room> rooms;
    std::vector<Entity> entities;
    Point start;
    Point exit;
};


#endif //DUNGEON_GENERATION_GENOTYPE_HPP
