#pragma once

// 1. Given an array of integers nums and an integer target,
//    return indices of the two numbers such that they add up to target.

// Solution: (complexity O(N))
// For each number:
// - Subtract it from target and record what's left.
// - If the remainder is present in num_to_index, return the two indices.
// - Otherwise record the current number-index pair into the map and continue.

SOLUTION_FOR_PROBLEM(1, "Two Sum") {

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_to_index;

    for (size_t i = 0; i < nums.size(); ++i) {
        int rem = target - nums[i];

        if (num_to_index.count(rem))
            return { num_to_index[rem], static_cast<int>(i) };

        num_to_index[nums[i]] = static_cast<int>(i);
    }

    return { -1, -1 };
}

SOLVE()
{
    std::vector<int> vec = { 3, 2, 4 };
    auto res = twoSum(vec, 6);
}

}
