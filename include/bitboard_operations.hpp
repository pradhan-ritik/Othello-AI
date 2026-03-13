#pragma once
#include "constants.hpp"

inline BB square_to_BB(int square) {
    assert(-1 < square < 64);
    return 1ULL << square;
}

inline void flip_bit(BB& bitboard, int bit) {
    assert(-1 < bit < 64);
    bitboard ^= square_to_BB(bit);
}

inline bool get_bit(BB bitboard, int bit) {
    assert(-1 < bit < 64);
    return bitboard & (square_to_BB(bit));
}

inline void add_bit(BB& bitboard, int bit) {
    assert(-1 < bit < 64);
    bitboard |= square_to_BB(bit);
}

inline bool contains(BB bitboard, BB other) {
    return (bitboard & other) == other;
}

inline int lsb(BB bitboard) {
    return __builtin_ctzll(bitboard);
}

inline int msb(BB bitboard) {
    return __builtin_clzll(bitboard) ^ 63;
}

inline int pop_lsb(BB& bitboard) {
    int lsb_ = lsb(bitboard);
    bitboard &= bitboard - 1;
    return lsb_;
}

inline int pop_msb(BB& bitboard) {
    int msb_ = msb(bitboard);
    bitboard ^= 1ULL << msb_;
    return msb_;
}

inline bool multiple_bits(BB bitboard) {
    return bitboard & (bitboard - 1);
}

inline bool only_one_bit(BB bitboard) {
    return bitboard && !multiple_bits(bitboard);
}

inline BB north(BB bitboard) {
    return bitboard << 8;
}

inline BB south(BB bitboard) {
    return bitboard >> 8;
}

inline BB east(BB bitboard) {
    return (bitboard & ~A_FILE) >> 1;
}

inline BB west(BB bitboard) {
    return (bitboard & ~H_FILE) << 1;
}

inline BB north_east(BB bitboard) {
    return north(east(bitboard));
}

inline BB north_west(BB bitboard) {
    return north(west(bitboard));
}

inline BB south_east(BB bitboard) {
    return south(east(bitboard));
}

inline BB south_west(BB bitboard) {
    return south(west(bitboard));
}

inline BB diagonal_bottom_right(int steps) {
    BB diagonal = 0x1020408001020408ULL;
    if (steps == 0) return diagonal;
    if (steps < 0) {
        while (steps++ < 0) {
            diagonal &= ~A_FILE;
            diagonal <<= 1;
        }
    }

    if (steps > 0) {
        while (steps-- > 0) {
            diagonal &= ~RANK_1;
            diagonal >>= 8;
        }
    }
}

inline void print_bitboard(BB bitboard) {
    for (int i = 63; i > -1; i--) {
        if ((i+1) % 8 == 0) {
            std::cout << "\n";
        }

        std::cout << get_bit(bitboard, i);
    }

    std::cout << "\n";
}
