#pragma once

// 136. Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// Solution: (complexity O(N))
// We make use of the fact that N ^ N == 0 and N ^ 0 == N.
// Basically, every number that's encounterd twice will xor
// itself out, and the only number that we'll have left is
// the number that we're looking for, that only used property 2
// and not 1.

SOLUTION_FOR_PROBLEM(136, "Single Number") {

int singleNumber(std::vector<int>& nums) {
    int answer = 0;

    for (auto num : nums)
        answer ^= num;

    return answer;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 1, 2, 5 };

    auto res = singleNumber(vec);
}

}
