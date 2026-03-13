#pragma once
#include <string>
#include "constants.hpp"
#include "bitboard_operations.hpp"

class Test {
    protected:
    std::string name;
    int assert_count;
    bool passed;
    public:
    // Test(std::string name) : name(name) {passed = true;}
    virtual void test_case() {};
    void run();
    bool _assert(bool expression, std::string expression_string);
};

class Bit_Ops : public Test {
    public:
    Bit_Ops() {
        name = "Bit Operations";
        passed = true;
    }

    void test_case();
};
