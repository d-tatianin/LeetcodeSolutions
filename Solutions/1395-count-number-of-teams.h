#pragma once

// 1395. Description too long to fit here https://leetcode.com/problems/count-number-of-teams/

// Solution: (complexity O(N^2))
// For each number:
// - Count numbers on the left of number that are greater and less
// - Count numbers on the right of number that are greater and less.
// - We now have 2 possible combinations:
//  [less_than_i, i, greater_than_i] - represented with left_less, i, right_greater
//  [greater_than_i, i, less_than_i] - represented with left_greater, i, right_less
//  Multiply both together and add to the total.

SOLUTION_FOR_PROBLEM(1395, "Count Number of Teams") {

int numTeams(std::vector<int>& rating) {
    size_t total = 0;

    for (size_t i = 0; i < rating.size(); ++i) {
        size_t left_greater = 0;
        size_t left_less = 0;
        size_t right_greater = 0;
        size_t right_less = 0;

        for (size_t j = 0; j < i; ++j) {
            if (rating[j] < rating[i])
                ++left_less;
            else
                ++left_greater;
        }

        for (size_t j = i + 1; j < rating.size(); ++j) {
            if (rating[j] < rating[i])
                ++right_less;
            else
                ++right_greater;
        }

        total += left_less * right_greater + left_greater * right_less;
    }

    return static_cast<int>(total);
}

SOLVE()
{
    std::vector<int> vec = { 2, 5, 3, 4, 1 };
    auto res = numTeams(vec);
}

}
