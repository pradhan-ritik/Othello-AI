#pragma once
#include "constants.hpp"
#include "bitboard_operations.hpp"

class Board {
    BB black, white;
    bool turn;

public:
    Board(std::string board_string);
    void print_board();

    inline BB get_black() { return black; }
    inline BB get_white() { return white; }
    inline BB get_full() { return white | black; }
    inline BB get_empties() { return ~(get_full()); }
    inline bool get_turn() { return turn; }
    inline void next_turn() { turn = !turn; }
};
