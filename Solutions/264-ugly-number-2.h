#pragma once

#include <vector>
#include <algorithm>

// 264. Write a program to find the n-th ugly number.

// Solution: (complexity O(N))
// Keep a pointer (index) for each prime into an array of N ugly numbers, all pointers start at 0.
// Start with 1 in the array and find the next smallest ugly number among the three primes.
// For each prime, increment its index into the array if multiplying array[pointer] * prime gives the current smallest ugly number.
// Note that we might have to increment multiple indicies per iteration, e.g 2 * 3 == 3 * 2.

namespace problem_264 {

inline int min_of_3(int x, int y, int z)
{
    return std::min(x, std::min(y, z));
}

inline int nth_ugly_number(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    std::vector<int> ugly_numbers(n);
    ugly_numbers[0] = 1;

    int pointer_2 = 0;
    int pointer_3 = 0;
    int pointer_5 = 0;

    for (int i = 1; i < n; ++i) {
        int next_ugly = min_of_3(ugly_numbers[pointer_2] * 2, ugly_numbers[pointer_3] * 3, ugly_numbers[pointer_5] * 5);
        ugly_numbers[i] = next_ugly;

        if (ugly_numbers[pointer_2] * 2 == next_ugly) pointer_2++;
        if (ugly_numbers[pointer_3] * 3 == next_ugly) pointer_3++;
        if (ugly_numbers[pointer_5] * 5 == next_ugly) pointer_5++;
    }

    return ugly_numbers.back();
}

}
