#pragma once

// 34. Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Solution: (complexity O(Log N))
// We use lower_bound to find the first occurence of an element, followed by upper_bound
// to find the last occurence of an element.

SOLUTION_FOR_PROBLEM(34, "Find First and Last Position of Element in Sorted Array") {

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    if (nums.empty())
        return { -1, -1 };

    auto lower = std::lower_bound(nums.begin(), nums.end(), target);
    auto upper = --std::upper_bound(nums.begin(), nums.end(), target); // decrement because upper_bound returns first element greater than target

    if (lower == nums.end() || *lower != target)
        return { -1, -1 };

    auto lower_index = static_cast<int>(std::distance(nums.begin(), lower));
    auto upper_index = static_cast<int>(std::distance(nums.begin(), upper));

    return { lower_index, upper_index };
}

SOLVE()
{
    std::vector<int> vec = { 5, 7, 7, 8, 8, 10 };
    auto range = searchRange(vec, 8);
}

}
