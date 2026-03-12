#include "board.hpp"

Board::Board(std::string board_string) {
    this->black = 0ULL;
    this->white = 0ULL;
    this->turn = BLACK;
    int length = board_string.length();
    int pos = -1;
    while (++pos < length) {
        char character = board_string[pos];
        if (character == 'B' || character == 'X')
            add_bit(this->black, pos);
        if (character == 'W' || character == 'O')
            add_bit(this->white, pos);
        if (character == ' ')
            this->turn = WHITE; // this acts for a flag to check for turn next character

        if (this->turn == WHITE) {
            this->turn = character == 'W';
            break;
        }
    }
}


void Board::print_board() {
    bool rank_start = true;
    std::cout << "TURN: " << (this->turn == BLACK ? "BLACK" : "WHITE") << std::endl;
    std::cout << "  A B C D E F G H" << std::endl;
    for (int sq = a1; sq >= h8; sq--) {
        if (rank_start) {
            std::cout << (((sq/8) ^ 7) + 1) << " ";
            rank_start = false;
        }

        if (get_bit(this->black, sq))
            std::cout << "B ";
        else if (get_bit(this->white, sq))
            std::cout << "W ";
        else
            std::cout << ". ";
        if (contains(BB(sq^0b111ULL), 0b111ULL)) {
            rank_start = true;
            std::cout << std::endl;
        }
    }
}
