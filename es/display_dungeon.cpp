//
// Created by Даниил on 23.10.2017.
//

#include "display_dungeon.hpp"


void output_dungeon_image_ascii (std::ostream &output, int dungeon [LEVEL_SIZE][LEVEL_SIZE]) {
    char symbol;
    for (int y = 0; y < LEVEL_SIZE; y++) {
        for (int x = 0; x < LEVEL_SIZE; x++) {
            switch (dungeon [y][x]) {
                case VOID:
                    symbol = ' ';
                    break;

                case FREE:
                    symbol = '=';
                    break;

                case WALL:
                    symbol = '#';
                    break;

                case MONSTER:
                    symbol = '$';
                    break;

                case TREASURE:
                    symbol = '?';
                    break;

                case START:
                    symbol = '@';
                    break;

                case EXIT:
                    symbol = '*';
                    break;

                default:
                    symbol = '!';
            }
            output.put (symbol);
        }
        output << std::endl;
    }
}