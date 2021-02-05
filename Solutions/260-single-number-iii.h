#pragma once

// 260. Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//      Find the two elements that appear only once. You can return the answer in any order.

// Solution: (complexity O(N))
// Exactly the same idea and first part as Single Number I,
// but here we get two numbers XORed into one, so in order to split them up,
// we detect a unique bit that's still set in the answer, and use that bit for
// the second traversal to separate numbers into two groups (group 1 for numbers
// with that bit set, and the other group for numbers that don't have that bit set)
// we XOR both groups with their own running answer, and at the end of the traversal
// we get two integers, which exactly match the single numbers.

SOLUTION_FOR_PROBLEM(260, "Single Number III") {

std::vector<int> singleNumber(std::vector<int>& nums) {
    long long int double_xor = 0;

    for (auto num : nums)
        double_xor ^= num;

    auto first_set_bit = (double_xor & -double_xor);

    int number_1 = 0;
    int number_2 = 0;

    for (auto num : nums) {
        if (num & first_set_bit)
            number_1 ^= num;
        else
            number_2 ^= num;
    }

    return { number_1, number_2 };
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 1, 3, 2, 5 };

    auto res = singleNumber(vec);
}

}
