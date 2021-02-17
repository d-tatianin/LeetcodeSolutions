#pragma once

// 46. Given an array nums of distinct integers, return all the possible permutations.
//     You can return the answer in any order.

// Solution: (complexity O(N!))
// Here's a great visualization: https://assets.leetcode.com/users/images/02477e9c-d6e6-4a48-9c7f-8f9b389ca820_1613366667.246253.png
// We basically swap a number with each consecutive number iteratively,
// while generating a permutation, and then unswapping again so that we can
// repeat on the next iteration.

SOLUTION_FOR_PROBLEM(46, "Permutations") {

void do_permute(std::vector<int>& nums, size_t index, std::vector<std::vector<int>>& out)
{
    if (index == nums.size()) {
        out.emplace_back(nums);
        return;
    }

    for (size_t i = index; i < nums.size(); ++i)
    {
        std::swap(nums[i], nums[index]);
        do_permute(nums, index + 1, out);
        std::swap(nums[i], nums[index]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> vec;
    do_permute(nums, 0, vec);
    return vec;
}

SOLVE()
{
    std::vector<int> vec = { 1, 2, 3 };
    permute(vec);
}

}
