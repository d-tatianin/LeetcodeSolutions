#pragma once

#include <cstring>

// 371. Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Solution: (complexity O(log N))
// 1. find intersecting bits of the two integers.
// 2. find non-intersecting bits of the two integers.
// 3. shift intersecting part left by 1 (emulating a carry bit).
// 4. repeat until there are no carry bits.

// Example:
// Adding 2 and 3
// 0b010
// 0b011
// intersecting bits -> 0b010
// non-intersecting bits -> 0b001
// intersecting shifted left by 1 -> 0b100
// after XORing non-intersecting with intersecting shifted left -> 0b101 (0b001 ^ 0b100)
// intersecting bits are now -> 0b000, so we're done

SOLUTION_FOR_PROBLEM(371, "Sum of Two Integers") {

int getSum(int l, int r)
{
    // We do this here because shifting negative numbers is undefined behavior as per the C++ standard.
    // This works because 2s complement addition is the same as unsigned addition.
    unsigned int left;
    unsigned int right;
    memcpy(&left, &l, sizeof(l));  // static_cast or (unsigned int) for negative values is also undefined behavior
    memcpy(&right, &r, sizeof(r)); // can use bit_cast instead of this for C++20

    while (right != 0) {
        unsigned int intersecting_bits = left & right;

        left ^= right; // non-intersecting bits

        right = intersecting_bits << 1;
    }

    // same reason for memcpy as above
    memcpy(&l, &left, sizeof(l));
    return l;
}

SOLVE()
{
    auto sum = getSum(-3, 5);
}

}
