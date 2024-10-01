#ifndef BITBOARD_OPERATIONS_HPP
#define BITBOARD_OPERATIONS_HPP

#include "constants.hpp"

inline BB square_to_BB(int square) {
    return 1ULL << square;
}

inline void flip_bit(BB& bitboard, int bit) {
    bitboard ^= square_to_BB(bit);
}

inline bool test_bit(BB bitboard, int bit) {
    return bitboard & (square_to_BB(bit));
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

inline void print_bitboard(BB bitboard) {
    for (int i = 63; i > -1; i--) {
        if ((i+1) % 8 == 0) {
            std::cout << "\n";
        }

        std::cout << test_bit(bitboard, i);
    }

    std::cout << "\n";
}

#endif // BITBOARD_OPERATIONS_HPP