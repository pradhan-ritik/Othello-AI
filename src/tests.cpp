#include "tests.hpp"

void Test::run() {
    std::cout << "Test case " << name << " starting\n";
    test_case();
    std::cout << "Did test case " << name << " pass? " << passed << "\n";
}

bool Test::_assert(bool expression, std::string expression_string) {
    assert_count++;
    passed &= expression;
    if (!expression) {
        std::cout << "Assert number " << assert_count << ", | " << expression_string << " | failed\n";
    }

    return expression;
}

void Bit_Ops::test_case() {
    assert(square_to_BB(b1) == 0b10);
    BB test = 0b10101011ULL;
    flip_bit(test, a1);
    assert(test == 0b10101010);
    assert(lsb(test) == b1);
    assert(msb(test) == h1);
    assert(pop_lsb(test) == b1);
    assert(test == 0b10101000);
    assert(pop_msb(test) == h1);
    assert(test == 0b101000);
    assert(multiple_bits(test));
    assert(!only_one_bit(test));
    assert(north(square_to_BB(a1)) == square_to_BB(a2));
    assert(south(square_to_BB(b2)) == square_to_BB(b1));
    assert(!east(square_to_BB(a2)));
    assert(east(square_to_BB(b2)) == square_to_BB(a2));
    assert(!west(square_to_BB(h1)));
    assert(west(square_to_BB(b1)) == square_to_BB(c1));
    // if these work, then we dont have to check north_east and the other multi directional functions
}