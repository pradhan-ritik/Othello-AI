#pragma once
#include "constants.hpp"

// packing the struct would make it slower to access but faster to create and use less ram
// T0DO: test if pragma pack is faster or slower than not using it
// #pragma pack(1)
struct Movelist {
private:
    Move moves[MAX_LEGAL_MOVES];
    uint8_t length;
public:
    Movelist() : length(0) {}

    inline void add_move(Move mv) { moves[index++] = mv; }
    // Doesn't actually clear just allows it to be overwritten
    inline Move pop_last_move() { return moves[length--]; }
    inline bool is_empty() { return length == 0; }
}
// #pragma pack()
