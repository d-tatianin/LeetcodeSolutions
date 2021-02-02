#pragma once

// 31. Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//     If such an arrangement is not possible, it must rearrange it as the lowest possible order(i.e., sorted in ascending order).
//     The replacement must be in placeand use only constant extra memory.

// Solution: (complexity O(N))
// - Find a number such that nums[index] < nums[index + 1]
// - If such a number doesn't exist, that means we're at teh final permutation, so reset the array by doing a reverse (same as sort() in this case)
// - Otherwise find the first number in the range [size() - 1, index + 1], such that it's greater than nums[index] (aka upper bound of number).
// - Swap the number with its upper bound and reverse the subarray from [index + 1, size() - 1].

SOLUTION_FOR_PROBLEM(31, "Next Permutation") {

void nextPermutation(std::vector<int>& nums) {
    auto perm_begin = is_sorted_until(nums.rbegin(), nums.rend());

    if (perm_begin != nums.rend())
        std::iter_swap(perm_begin, upper_bound(nums.rbegin(), perm_begin, *perm_begin));

    std::reverse(nums.rbegin(), perm_begin);
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3 };
    nextPermutation(vec);
}

}
