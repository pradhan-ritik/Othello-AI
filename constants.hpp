#pragma once
#include <iostream>
#include <string>
#include <assert.h>

typedef unsigned long long BB;

enum Square {
    h8, g8, f8, e8, d8, c8, b8, a8,
    h7, g7, f7, e7, d7, c7, b7, a7,
    h6, g6, f6, e6, d6, c6, b6, a6,
    h5, g5, f5, e5, d5, c5, b5, a5,
    h4, g4, f4, e4, d4, c4, b4, a4,
    h3, g3, f3, e3, d3, c3, b3, a3,
    h2, g2, f2, e2, d2, c2, b2, a2,
    h1, g1, f1, e1, d1, c1, b1, a1,
};

inline constexpr int SQUARE_NB = 64;
// 33 in reachable positions, and 34 in unreachable position
// It is 34 just in case in some point I will allow the user to set positions
inline constexpr int MAX_LEGAL_MOVES = 34;

inline constexpr BB H_FILE = 0x0101010101010101ULL;
inline constexpr BB G_FILE = H_FILE << 1;
inline constexpr BB F_FILE = H_FILE << 2;
inline constexpr BB E_FILE = H_FILE << 3;
inline constexpr BB D_FILE = H_FILE << 4;
inline constexpr BB C_FILE = H_FILE << 5;
inline constexpr BB B_FILE = H_FILE << 6;
inline constexpr BB A_FILE = H_FILE << 7;

inline constexpr BB RANK_1 = 0xFF;
inline constexpr BB RANK_2 = RANK_1 << 8;
inline constexpr BB RANK_3 = RANK_1 << 16;
inline constexpr BB RANK_4 = RANK_1 << 24;
inline constexpr BB RANK_5 = RANK_1 << 32;
inline constexpr BB RANK_6 = RANK_1 << 40;
inline constexpr BB RANK_7 = RANK_1 << 48;
inline constexpr BB RANK_8 = RANK_1 << 56;

inline const std::string STARTING_BOARD = "...........................WB......BW........................... B";
enum {
    BLACK,
    WHITE
};
