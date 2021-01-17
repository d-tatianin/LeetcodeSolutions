#pragma once

#include <vector>
#include <algorithm>

// 53. Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Solution: (complexity O(N))
// For each number in the array:
// - Either add it to the current sum, or reset the current sum with it, depending on what yields greater value
// - Set max sum to current sum if current sum is greater than max sum

namespace problem_53 {

int maximum_subarray(std::vector<int>& numbers) {
    if (numbers.empty())
        return 0;

    int current_sum = 0;
    int biggest_sum = INT_MIN;
 
    for (auto number : numbers) {
        current_sum = std::max(current_sum + number, number);
        biggest_sum = std::max(current_sum, biggest_sum);
    }
 
 
    return biggest_sum;
}

}
