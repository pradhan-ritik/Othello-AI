#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <iostream>

typedef unsigned long long BB;

enum Square {
    a1, b1, c1, d1, e1, f1, g1, h1,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a8, b8, c8, d8, e8, f8, g8, h8,
};

inline constexpr int SQUARE_NB = 64;
// 33 in reachable positions, and 34 in unreachable position
// It is 34 just in case in some point I will allow the user to set positions
inline constexpr int MAX_LEGAL_MOVES = 34;

inline constexpr BB A_FILE = 0x0101010101010101ULL;
inline constexpr BB B_FILE = A_FILE << 1;
inline constexpr BB C_FILE = A_FILE << 2;
inline constexpr BB D_FILE = A_FILE << 3;
inline constexpr BB E_FILE = A_FILE << 4;
inline constexpr BB F_FILE = A_FILE << 5;
inline constexpr BB G_FILE = A_FILE << 6;
inline constexpr BB H_FILE = A_FILE << 7;

inline constexpr BB RANK_1 = 0xFF;
inline constexpr BB RANK_2 = RANK_1 << 8;
inline constexpr BB RANK_3 = RANK_1 << 16;
inline constexpr BB RANK_4 = RANK_1 << 24;
inline constexpr BB RANK_5 = RANK_1 << 32;
inline constexpr BB RANK_6 = RANK_1 << 40;
inline constexpr BB RANK_7 = RANK_1 << 48;
inline constexpr BB RANK_8 = RANK_1 << 56;

#endif // CONSTANTS_HPP