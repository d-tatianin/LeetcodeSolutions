#pragma once

#include <vector>
#include <algorithm>

// 15. Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Solution: (complexity O(N^2))
// 1. Sort the array so we can use two pointers below.
// 2. For each number in the array:
// - Find the target sum that we're looking for from two other numbers, aka 0 - array[i].
// - Start iterating the rest of the array with high and low pointers.
// - if sum of two elements at pointers is less than target we increment the low pointer.
// - if sum of two elements at pointers is greater than target we decrement the high pointer.
// - otherwise we found a match, so push the result into the vector.
// - to avoid duplicates in the array, increment low and decrement high as long as next element == previous.

PROBLEM(15, "3Sum") {

inline std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    if (nums.size() < 3)
        return {};

    std::vector<std::vector<int>> vec;

    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 2; ++i) {
        if (i && nums[i] == nums[i - 1])
            continue;

        size_t low = i + 1;
        size_t high = nums.size() - 1;
        auto target = 0 - nums[i];

        while (low < high) {
            auto sum = nums[low] + nums[high];

            if (sum < target)
                ++low;
            else if (target < sum)
                --high;
            else { // target == sum
                vec.push_back({ nums[i], nums[low], nums[high] });

                while (low < high && nums[low]  == nums[low + 1])  ++low;
                while (low < high && nums[high] == nums[high - 1]) --high;
                ++low;
                --high;
            }
        }
    }

    return vec;
}

TRY_SOLVE()
{
    std::vector<int> v = { -1, 0, 1, 2, -1, -4 };

    auto res = threeSum(v);
}

}
