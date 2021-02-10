#pragma once

// 989. For a non-negative integer X, the array-form of X is an array of its digits in left to right order.

// Solution: (complexity O(N))
// We add the current power of 10 number in A to K if it exists
// and push the % 10 remainder of K into the array, while shifting K
// left by 1 in base 10 (dividing by 10), until it becomes 0.

SOLUTION_FOR_PROBLEM(989, "Add to Array-Form of Integer") {

std::vector<int> addToArrayForm(std::vector<int>& A, int K) {
    std::vector<int> out;
    out.reserve(A.size());

    int i = static_cast<int>(A.size());

    while (--i >= 0 || K) {
        if (i >= 0) {
            K += A[i];
        }

        out.push_back(K % 10);
        K /= 10;
    }

    std::reverse(out.begin(), out.end());

    return out;
}

SOLVE()
{
    std::vector<int> vec = { 2, 1, 5 };
    auto res = addToArrayForm(vec, 806);
}

}
