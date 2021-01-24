#pragma once

#include <vector>
#include <utility>

// 905. Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// Solution: (complexity O(N))
// Create two pointers, i = 0, and j = last index in array
// while i < j:
// - if number at i is odd, we swap it with number at index j and decrement j
// - otherwise number at i is even and therefore at its correct position, so increment i

PROBLEM(905, "Sort Array By Parity") {

inline std::vector<int> sortArrayByParity(std::vector<int>& A) {
    if (A.empty())
        return {};

    size_t i = 0;
    size_t j = A.size() - 1;

    while (i < j) {
        if (A[i] % 2) {
            std::swap(A[i], A[j--]);
            continue;
        }

        i++;
    }

    return A;
}

TRY_SOLVE()
{
    std::vector<int> vec = { 3, 1, 2, 4 };

    auto res = sortArrayByParity(vec);
}

}
