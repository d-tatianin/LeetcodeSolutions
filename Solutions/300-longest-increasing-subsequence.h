#pragma once

// 300. Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Solution: (complexity O(N Log N))
// -------------------------------------- N LOG N solution ---------------------------------------------
// For each element in the nums array:
// - If res array contains a number greater or equal to current, replace that number with current number.
// - Otherwise add current number to the array.
// The length of the final res array is the longest subsequence.
// -------------------------------------- N^2 solution -------------------------------------------------
// We use two pointers, i and j, i starts at 0, and j starts at 1.
// We also create a res array, which represents lengths of the longest subsequence at each index.
// j represents the end of current subarray and i always starts at 0.
// The idea here is we compare every element against every other element and increment by 1 where nums[j] > nums[i],
// while tracking the current maximum length.

SOLUTION_FOR_PROBLEM(300, "Longest Increasing Subsequence") {

int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> res;
    res.reserve(nums.size());

    for (auto num : nums) {
        auto lb = std::lower_bound(res.begin(), res.end(), num);

        if (lb == res.end())
            res.push_back(num);
        else
            *lb = num;
    }

    return static_cast<int>(res.size());
}

int slowLengthOfLIS(std::vector<int>& nums) {
    int biggest = 1;

    std::vector<int> idx_to_length(nums.size(), 1);

    for (size_t j = 1; j < nums.size(); ++j) {
        for (size_t i = 0; i < j; ++i) {
            if (nums[j] <= nums[i])
                continue;

            idx_to_length[j] = std::max(idx_to_length[j], idx_to_length[i] + 1);

            if (idx_to_length[j] > biggest)
                biggest = idx_to_length[j];
        }
    }

    return biggest;
}

SOLVE()
{
    std::vector<int> vec = { 10, 9, 2, 5, 3, 7, 101, 18 };

    auto res = lengthOfLIS(vec);
    auto res1 = slowLengthOfLIS(vec);
}

}
