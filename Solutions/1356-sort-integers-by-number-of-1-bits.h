#pragma once

// 1356. You have to sort the integers in the array in ascending order by the number of 1's in their
//       binary representation and in case of two or more integers have the same number of 1's 
//       you have to sort them in ascending order.

// Solution: (complexity O(N Log N))
// Just use std::sort with a custom predicate, that uses
// Brian Kernighan's algorithm to count set bits as fast as possible.
// (as a hack we could also use __builtin_popcount())

SOLUTION_FOR_PROBLEM(1356, "Sort Integers by The Number of 1 Bits") {

std::vector<int> sortByBits(std::vector<int>& arr) {
    auto count_bits = [](int x)
    {
        size_t count = 0;

        for (; x; ++count)
            x &= x - 1;

        return count;
    };

    std::sort(arr.begin(), arr.end(),
        [&](int l, int r)
        {
            auto ll = count_bits(l);
            auto lr = count_bits(r);

            return ll == lr ? l < r : ll < lr;
        });

    return arr;
}

SOLVE()
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    auto res = sortByBits(vec);
}

}
