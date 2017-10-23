//
// Created by daniil on 23.10.17.
//

#ifndef DUNGEON_GENERATION_METAINFO_HPP
#define DUNGEON_GENERATION_METAINFO_HPP


struct Metainfo {
    bool start_exist = false;
    bool exit_exist = false;
    bool exit_reachable = false;

    int monsters = 0;
    int treasures = 0;

    int overall_area = 0;
    int reachable_area = 0;
};


#endif //DUNGEON_GENERATION_METAINFO_HPP
