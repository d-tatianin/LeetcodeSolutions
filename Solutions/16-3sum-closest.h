#pragma once

#include <climits>
#include <vector>
#include <algorithm>

// 16. Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
//     Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Solution: (complexity O(N^2))
// Same idea as 3sum, but we have a variable instead of a vector.
// For each sum we check if it's closer to the number than our previous sum, if it is we record it.

SOLUTION_FOR_PROBLEM(16, "3Sum Closest") {

int threeSumClosest(std::vector<int>& nums, int target) {
    if (nums.size() < 3)
        return 0;

    std::sort(nums.begin(), nums.end());

    int best_delta = INT_MAX;

    for (size_t i = 0; i < nums.size() - 2; ++i) {
        if (i && nums[i] == nums[i - 1])
            continue;

        size_t low = i + 1;
        size_t high = nums.size() - 1;

        while (low < high) {
            auto sum = nums[low] + nums[high] + nums[i];

            auto delta = target - sum;

            if (abs(delta) < abs(best_delta))
                best_delta = delta;

            if (sum < target)
                ++low;
            else if (target < sum)
                --high;
            else
                return target;
        }
    }

    return target - best_delta;
}

SOLVE()
{
    std::vector<int> v = { -1, 2, 1, -4 };

    auto res = threeSumClosest(v, 1);
}

}
