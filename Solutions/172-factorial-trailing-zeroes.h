#pragma once

// 172. Given an integer n, return the number of trailing zeroes in n!.

// Solution: (complexity O(log N))
// Since trailing zeroes come from 10, which in turn comes from 5 * 2, we need to calculate how many
// such multiplications a factorial includes. We can do this by dividing n by five until it becomes smaller than 5.

PROBLEM(172, "Factorial Trailing Zeroes") {

inline int trailingZeroes(int n)
{
    int zeroes = 0;

    while (n >= 5) {
        n /= 5;
        zeroes += n;
    }

    return zeroes;
}

TRY_SOLVE()
{
    auto res = trailingZeroes(100);
}

}
