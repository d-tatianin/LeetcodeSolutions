#pragma once

// 724. Given an array of integers nums, write a method that returns the "pivot" index of this array.

// Solution: (complexity O(N))
// - Calculate the cumulative sum of all elements.
// For each number in the array:
// - if cumulative_sum - current_sum - number == current_sum, we found a pivot
// - otherwise add current number to current_sum

PROBLEM(724, "Find Pivot Index") {

int pivotIndex(std::vector<int>& nums) {
    int sum = 0;

    for (auto num : nums)
        sum += num;

    int current_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (sum - current_sum - nums[i] == current_sum)
            return i;

        current_sum += nums[i];
    }

    return -1;
}

TRY_SOLVE()
{
    std::vector<int> vec = { 1, 7, 3, 6, 5, 6 };

    auto res = pivotIndex(vec);
}

}
