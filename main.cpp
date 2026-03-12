#include "constants.hpp"
#include "bitboard_operations.hpp"
#include "board.hpp"
#include "tests.hpp"

int main() {
    Board b = Board(STARTING_BOARD);
    b.print_board();
    return 0;
}
