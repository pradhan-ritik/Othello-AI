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
    inline bool is_empty(int square) { return get_empties() & square_to_BB(square); }
    inline bool is_white(int square) { return white & square_to_BB(square); }
    inline bool is_black(int square) { return black & square_to_BB(square); }
};
