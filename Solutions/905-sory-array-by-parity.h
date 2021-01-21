#pragma once

#include <vector>
#include <utility>

// 905. Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// Solution: (complexity O(N))
// Create two pointers, i = 0, and j = last index in array
// while i < j:
// - if number at i is odd, we swap it with number at index j and decrement j
// - otherwise number at i is even and therefore at its correct position, so increment i

namespace problem_905 {

inline std::vector<int> sort_array_by_parity(std::vector<int>& A) {
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

}
