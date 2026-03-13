#include "constants.hpp"
#include "bitboard_operations.hpp"
#include "board.hpp"
#include "tests.hpp"

int main() {
    Board b = Board(STARTING_BOARD);
    b.print_board();
    std::cout << b.is_white(d4) << std::endl;
    std::cout << b.is_black(d5) << std::endl;
    std::cout << b.is_empty(d6) << std::endl;
    return 0;
}
